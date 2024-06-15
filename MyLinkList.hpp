#ifndef MYLINKLIST_H
#define MYLINKLIST_H

namespace MyListNode
{
    template <typename T>
    struct ListNode
    {
        T val;
        ListNode *nextNode;
        ListNode(T nodeval) : val(nodeval), nextNode(nullptr){};
    };

    template <typename T>
    void insert(ListNode<T> *node, ListNode<T> *insertedNode);

    template <typename T>
    void removeAfter(ListNode<T> *node);

    template <typename T>
    ListNode<T> *acsses(ListNode<T> *head, int index);

    template <typename T>
    int find(ListNode<T> *head, T target);

    template <typename T>
    void printListNode(ListNode<T> *head);

    template <typename T>
    void freeMemoryListNode(ListNode<T> *currentNode);
}

#endif // MYLINKLIST_H