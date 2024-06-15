#include "./MyLinkList.hpp"
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <deque>
namespace MyQueue
{   
    using namespace MyListNode;
    template <typename T>
    class LinkedListQueue
    {
    private:
        ListNode<T> *front, *rear;
        int queueSize;

        std::string toString()
        {
            std::vector<T> queueVector = this->toVector();
            std::string result = "{";
            for (int i = 0; i < queueVector.size(); i++)
            {
                result += std::to_string(queueVector[i]);
                if (i < queueVector.size() - 1)
                {
                    result += ", ";
                }
            }
            result += "}";
            return result;
        }
    public:
        LinkedListQueue(/* args */) : front(nullptr), rear(nullptr), queueSize(0) {};
        ~LinkedListQueue() {};

        int size()
        {
            return this->queueSize;
        }

        void push(T val)
        {
            ListNode<T> * newNode = new ListNode<T>(val);
            if (this->front == nullptr)
            {
                this->front = newNode;
                this->rear = newNode;
            }
            
            else
            {
                this->rear->nextNode = newNode;
                this->rear = newNode;

            }
            this->queueSize++;

        }

        T peek()
        {
            if (this->front == nullptr)
            {
                throw std::out_of_range("空队列");
            }
            return this->front->val;
        }

        T pop()
        {
            T poped = this->peek();
            ListNode<T> *tmp = this->front;
            this->front = this->front->nextNode;
            delete tmp;
            this->queueSize--;
            return poped;
        }

        std::vector<T> toVector()
        {
            ListNode<T> *node = this->front;
            std::vector<T> result(this->size());
            for (int i = 0; i < result.size(); i++)
            {
                result[i] = node->val;
                node = node->nextNode;
            }

            return result;
            
        }

        
        operator std::string()
        {
            return this->toString();
        }
    };
    
    
    
    
    
    
    
    
    
} // namespace MyQueue

