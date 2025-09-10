#include <codecvt>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    auto cmp = [](int a, int b) {return a > b;};
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;
    
    
    minHeap.push(1);
    minHeap.push(3);
    minHeap.push(2);


    maxHeap.push(1);
    maxHeap.push(3);
    maxHeap.push(2);
    
    int peek = maxHeap.top();
    std::cout << peek;


    return 0;
}