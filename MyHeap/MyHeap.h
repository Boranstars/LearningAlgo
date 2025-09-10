//
// Created by boran on 2025/9/10.
//

#ifndef LEARNINGALGO_MYHEAP_H
#define LEARNINGALGO_MYHEAP_H
#include <algorithm>
#include <cstddef>
#include <functional>
#include <optional>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>


template <typename T,typename Compare = std::less<T>>
class ArrayHeap {
private:
    Compare _comp;
    // 堆实现数组
    std::vector<T> _heap;
    static constexpr int default_capacity = 10;

    int left(int index) const {
        return 2 * index + 1;
    }

    int right(int index) const {
        return 2 * index + 2;
    }

    int parent(int index) const {
        return (index - 1) / 2;
    }

    /**
     * @brief 堆化上浮操作，从i开始从底向顶堆化
     * 
     * @param i 
     */
    void shiftUp(int i) {
        while (i > 0) {
            int p = parent(i);
            // 如果父节点在比较器下“优于”子节点，则停止；否则交换
            // 对于默认 std::less (a<b)，当 comp(parent, child) == true 表示 child 更优，需要上浮
            if (!_comp(_heap[p], _heap[i])) {
                break;
            }
            std::swap(_heap[i], _heap[p]);
            i = p;
        }
    }

    void shiftDown(int i) {
        // 这里将根节点和其两个子节点的值做比较，得到最优子节点，再交换
        while (true) {
            int l = left(i);
            int r = right(i);
            int best = i;
            if (l < static_cast<int>(size()) && _comp(_heap[best], _heap[l])) {
                best = l;
            }
            if (r < static_cast<int>(size()) && _comp(_heap[best], _heap[r])) {
                best = r;
            }
            // 如果当前节点已经是最优节点，说明堆化完成
            if (best == i) {
                break;
            }
            // 否则交换
            std::swap(_heap[i], _heap[best]);
            // 继续向下堆化
            i = best;
        }
    }

public:

    explicit ArrayHeap() {
        _heap.reserve(default_capacity);
    }

    ArrayHeap(const Compare& comp)  : _comp(comp) {
        _heap.reserve(default_capacity);
    }

    ArrayHeap(std::vector<T> vec, const Compare& comp = Compare()) : _heap(std::move(vec)), _comp(comp) {
        // 从最后一个非叶节点开始，依次向前堆化（注意(size() / 2) - 1 实际上就是parent(size() - 1)）
        // 而叶子节点天然满足堆性质，无需堆化
        // 堆化
        for (int i = static_cast<int>(size() / 2) - 1; i >= 0; --i) {
            shiftDown(i);
        }
    }

    const T& peek() const {
        if (isEmpty()) throw std::out_of_range("堆为空");
        return _heap[0];
    }

    size_t size() const
    {
        return _heap.size();
    }

    [[nodiscard]] bool isEmpty() const
    {
        return this->size() == 0;
    }

    void push(const T& val) {
        _heap.push_back(val);
        shiftUp(static_cast<int>(size()) - 1);
    }

    void push(T&& val) {
        _heap.push_back(std::move(val));
        shiftUp(static_cast<int>(size()) - 1);
    }

    std::optional<T> pop() {
        
        if (isEmpty()) {
            
            // throw std::out_of_range("堆为空");
            return std::nullopt;
        }
        T popped = std::move(_heap.at(0));

        // 交换根节点和最右节点
        std::swap(_heap[0], _heap[size() - 1]);
        // 删除节点
        _heap.pop_back();
        //从顶向下堆化
        shiftDown(0);

        return popped;

    }

    friend std::ostream& operator<<(std::ostream& os, const ArrayHeap& heap) {
        os << "[";
        for (size_t i = 0; i < heap.size(); ++i) {
            os << heap._heap[i];
            if (i != heap.size() - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

   

    void printTree(int idx = 0, int depth = 0) const {
        if (idx >= _heap.size()) return;
        // 打印右子树
        printTree(right(idx), depth + 1);
        // 打印当前节点
        for (int i = 0; i < depth; ++i) std::cout << "    ";
        std::cout << _heap[idx] << std::endl;
        // 打印左子树
        printTree(left(idx), depth + 1);
    }


};
#endif // LEARNINGALGO_MYHEAP_H
