#ifndef MYLINKLIST_H
#define MYLINKLIST_H

/**
 * @namespace MyListNode
 * @brief 包含了与链表相关的操作的命名空间。
 */
namespace MyListNode
{   
    /**
     * @brief 链表节点的结构体。
     * 
     * @tparam T 节点存储的值的类型。
     */
    template <typename T>
    struct ListNode
    {
        T val;              // 节点存储的值
        ListNode *nextNode; // 指向下一个节点的指针
        ListNode *prevNode; // 指向前一个节点的指针

        /**
         * @brief 构造函数，用于初始化节点。
         * 
         * @param nodeval 节点存储的值。
         */
        ListNode(T nodeval) : val(nodeval), nextNode(nullptr), prevNode(nullptr) {};
    };

    /**
     * @brief 在指定节点后插入一个新节点。
     * 
     * @tparam T 节点存储的值的类型。
     * @param node 指定节点。
     * @param insertedNode 要插入的新节点。
     */
    template <typename T>
    void insert(ListNode<T> *node, ListNode<T> *insertedNode);

    /**
     * @brief 删除指定节点后的节点。
     * 
     * @tparam T 节点存储的值的类型。
     * @param node 指定节点。
     */
    template <typename T>
    void removeAfter(ListNode<T> *node);

    /**
     * @brief 访问链表中指定索引的节点。
     * 
     * @tparam T 节点存储的值的类型。
     * @param head 链表的头节点。
     * @param index 要访问的节点的索引。
     * @return 指定索引处的节点，如果索引超出范围则返回nullptr。
     */
    template <typename T>
    ListNode<T> *acsses(ListNode<T> *head, int index);

    /**
     * @brief 在链表中查找目标值的第一次出现的索引。
     * 
     * @tparam T 节点存储的值的类型。
     * @param head 链表的头节点。
     * @param target 要查找的目标值。
     * @return 目标值第一次出现的索引，如果未找到则返回-1。
     */
    template <typename T>
    int find(ListNode<T> *head, T target);

    /**
     * @brief 打印链表中节点的值。
     * 
     * @tparam T 节点存储的值的类型。
     * @param head 链表的头节点。
     */
    template <typename T>
    void printListNode(ListNode<T> *head);

    /**
     * @brief 释放链表中节点的内存。
     * 
     * @tparam T 节点存储的值的类型。
     * @param currentNode 要开始释放内存的当前节点。
     */
    template <typename T>
    void freeMemoryListNode(ListNode<T> *currentNode);
}

#endif // MYLINKLIST_H