#include <iostream>

namespace MylistNode
{   
    template<typename T>
    struct ListNode
    {
        T val;
        ListNode *nextNode;
        ListNode(T nodeval) : val(nodeval), nextNode(nullptr) {};
    };

    template<typename T>
    void insert(ListNode<T> *node, ListNode<T> *insertedNode)
    {
        insertedNode->nextNode = node->nextNode;
        node->nextNode = insertedNode;
    }

    template<typename T>
    void removeAfter(ListNode<T> *node)
    {
        if (node->nextNode == nullptr)
        {
            return;
        }
        
        ListNode<T> *P = node->nextNode;
        node->nextNode = P->nextNode;
        delete P;
    }

    template<typename T>
    ListNode<T> *acsses(ListNode<T> *head, int index)
    {
        for (int i = 0; i < index; i++)
        {
            if (head == nullptr)
            {
                return nullptr;
            }
            head = head->nextNode;
        }
        return head;
    }

    template<typename T>
    int find(ListNode<T> *head, T target) 
    {
        int index(0);
        while (head != nullptr)
        {
            if (head->val == target)
            {
                return index;
            }
            head = head->nextNode;
            ++index;
        }
        return -1;
        
    }

    template<typename T>
    void printListNode(ListNode<T> *head) 
    {
        while (head != nullptr)
        {
            std::cout << head->val;
            if(head->nextNode != nullptr) std::cout << "->";
            head = head->nextNode;
        }
        std::cout << std::endl;
    }

} // namespace MylistNode
