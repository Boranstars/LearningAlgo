#include "MyHeap.h"

int main() {
    std::vector<int> data = {5, 3, 8, 1, 2, 7};
    ArrayHeap<int> maxHeap(data); // 默认是大顶堆
    ArrayHeap<int, std::greater<int>> minHeap(data); // 小顶堆
    std::cout << "Max-Heap: " << maxHeap << std::endl;
    std::cout << "Min-Heap: " << minHeap << std::endl;
    std::cout << "Max-Heap Tree Structure:\n";
    maxHeap.printTree(); // 打印堆的结构
    std::cout << "Min-Heap Tree Structure:\n";
    minHeap.printTree(); // 打印堆的结构

    maxHeap.push(6);
    minHeap.push(0);
    std::cout << "After pushing 6 to Max-Heap: " << maxHeap << std::endl;
    maxHeap.printTree();
    std::cout << "After pushing 0 to Min-Heap: " << minHeap << std::endl;
    minHeap.printTree();
}