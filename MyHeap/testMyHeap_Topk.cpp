#include "MyHeap.h"

#include <iostream>

struct StudentInfo {
    std::string name;
    int score;

    // 定义 < 运算符，按分数从大到小排序
    bool operator<(const StudentInfo& other) const {
        return score < other.score; // 分数低的被认为“更小”
    }

    bool operator>(const StudentInfo& other) const {
        return score > other.score;
    }

    // 为了方便打印
    friend std::ostream& operator<<(std::ostream& os, const StudentInfo& student) {
        os << "{" << student.name << ": " << student.score << "}";
        return os;
    }
};

int main() {
    // 利用自定义堆实现 Top-K 问题

    // 测试基本类型
    std::vector<int> data = {5, 3, 8, 1, 2, 7};
    int k = 3;

    // 使用小顶堆维护前 k 大元素
    ArrayHeap<int, std::greater<int>> minHeap;
    
    // 先将前 k 个元素加入堆
    for (int i = 0; i < k && i < static_cast<int>(data.size()); ++i) {
        minHeap.push(data[i]);
    }
    // 处理剩余元素
    for (int i = k; i < static_cast<int>(data.size()); ++i) {
        if (data[i] > minHeap.peek()) {
            minHeap.pop();
            minHeap.push(data[i]);
        }
    }

    std::cout << "Top " << k << " elements: " << minHeap << std::endl;


    // 测试自定义类型
    std::vector<StudentInfo> students = {{"Alice", 85}, {"Bob", 92}, {"Charlie", 78}, {"David", 90}};
    k = 2;

    // 使用小顶堆维护前 k 大元素
    ArrayHeap<StudentInfo, std::greater<StudentInfo>> minHeap2;
    for (const auto& student : students) {
        minHeap2.push(student);
        if (minHeap2.size() > k) {
            minHeap2.pop();
        }
    }
    // 这两种找前 k 大的方法都可以，但是第一种更高效

    std::cout << "Top " << k << " students: " << minHeap2 << std::endl;
    minHeap2.printTree();

    return 0;
}