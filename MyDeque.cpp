#include "MyLinkList.hpp"
#include "MyQueue.cpp"

#include <stdexcept>
namespace MyQueue
{
    using namespace MyListNode;

    template <typename T>

    class LinkedListDeque
    {
    private:
        int queSize;
        ListNode<T> *front, *rear;

        void push(T val, bool isFront = false)
        {
            ListNode<T> *newNode = new ListNode<T>(val);
            // 若链表为空，则令 front 和 rear 都指向 node
            if (this->isEmpty())
            {
                this->front = this->rear = newNode;
            }
            // 队首入队操作
            else if (isFront)
            {
                this->front->prevNode = newNode;
                newNode->nextNode = this->front;
                this->front = newNode; // 更新头节点
            }
            // 队尾入队操作
            else
            {
                this->rear->nextNode = newNode;
                newNode->prevNode = this->rear;
                this->rear = newNode;
            }
            this->queSize++;
        }

        T pop(bool isFront)
        {
            if (this->isEmpty())
            {
                throw std::out_of_range("队列为空");
            }

            T poped;
            if (isFront)
            {
                poped = this->front->val;

                ListNode<T> *fNext = front->nextNode;
                if (fNext != nullptr)
                {
                    fNext->prevNode = nullptr;
                    this->front->nextNode = nullptr;
                }
                delete this->front;
                this->front = fNext;
            }
            else
            {
                poped = this->rear->val;
                ListNode<T> *rPrev = this->rear->prevNode;
                if (rPrev != nullptr)
                {
                    rPrev->nextNode = nullptr;
                    this->rear->prevNode = nullptr;
                }
                delete this->rear;
                this->rear = rPrev;
            }
            this->queSize--;
            return poped;
        }

        std::string toString() const
        {
            std::string str = "[";
            ListNode<T> *cur = this->front;
            while (cur != nullptr)
            {
                str += std::to_string(cur->val);
                if (cur->nextNode != nullptr)
                {
                    str += ", ";
                }
                cur = cur->nextNode;
            }
            str += "]";
            return str;
        }

    public:
        LinkedListDeque()
        {
        }
        ~LinkedListDeque() {}

        int size()
        {
            return this->queSize;
        }

        bool isEmpty()
        {
            return this->size() == 0;
        };

        void pushFirst(T val)
        {
            this->push(val, true);
        }

        void pushLast(T val)
        {
            this->push(val, false);
        }

        T popFirst()
        {
            return pop(true);
        }

        T popLast()
        {
            return pop(false);
        }

        T peekFrist()
        {
            if (this->isEmpty())
            {
                throw std::out_of_range("队列为空");
            }
            return this->front->val;
        }

        T peekLast()
        {
            if (this->isEmpty())
            {
                throw std::out_of_range("队列为空");
            }
            return this->rear->val;
        }

        operator std::string() const
        {
            return this->toString();
        }
    };
}