#include "MyHeap.h"
#include <iostream>
#include <vector>

int main() {
    // Test 1: 默认比较器（std::less） -> 大顶堆
    {
        ArrayHeap<int> h;
        for (int x : {5, 1, 3, 7, 2}) h.push(x);

    std::cout << "Heap dump: "<< h; std::cout << "\nTree:\n"; h.printTree();

        std::vector<int> popped;
        while (!h.isEmpty()) {
            auto v = h.pop();
            if (v) popped.push_back(*v);
        }
        std::vector<int> expect = {7,5,3,2,1};
        if (popped == expect) std::cout << "max-heap pop order OK\n";
        else {
            std::cout << "max-heap pop order FAIL\n";
            return 1;
        }
    }

    // Test 2: 传入自定义比较器 -> 小顶堆
    {
        ArrayHeap<int, std::greater<int>> mh;
        for (int x : {5, 1, 3, 7, 2}) mh.push(x);
        std::vector<int> popped;
        while (!mh.isEmpty()) {
            auto v = mh.pop();
            if (v) popped.push_back(*v);
        }
        std::vector<int> expect = {1,2,3,5,7};
        if (popped == expect) std::cout << "min-heap pop order OK\n";
        else {
            std::cout << "min-heap pop order FAIL\n";
            return 1;
        }
    }

    // Test 3: pop on empty returns nullopt
    {
        ArrayHeap<int> h;
        auto v = h.pop();
        if (!v) std::cout << "pop on empty returns nullopt OK\n";
        else {
            std::cout << "pop on empty FAIL\n";
            return 1;
        }
    }

    std::cout << "All tests passed\n";
    return 0;
}
