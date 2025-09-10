#include "MyAvlTree.cpp"
#include <iostream>



using  IntAvlTree = AVlTree<int>;

void test1() {
    IntAvlTree tree;
    tree.insert(1);
    tree.insert(10);
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(6);
    tree.insert(8);
    tree.insert(9);
    tree.insert(2);
    tree.insert(4);
    tree.insert(11);
    tree.insert(12);

    std::vector<int> result;
    tree.inOrder(tree.getRoot(), result);
    for (auto &val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    tree.remove(10);
    tree.remove(5);
    result.clear();
    std::cout << "-----" << std::endl;
    
    tree.insert(8);
    tree.insert(5);
    
    tree.inOrder(tree.getRoot(), result);
    for (auto &val : result) {
        std::cout << val << " ";
    }
    delete tree.getRoot();
    result.clear();
    std::cout << std::endl;
}

void test2()
{
    IntAvlTree tree;
    std::vector<int> result;

    // 设置随机数种子
    std::srand(std::time(nullptr));

    // 插入随机数
    for (int i = 0; i < 100000; ++i) {
        int randomValue = std::rand() % 100000; // 生成 0 到 99 之间的随机数
        tree.insert(randomValue);
    }

    // 中序遍历并输出结果
    tree.inOrder(tree.getRoot(), result);
    for (auto &val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}
int main(int argc, const char** argv) {
    test2();
    return 0;
}