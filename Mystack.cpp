#include "MyLinkList.cpp"
#include <vector>
#include <stdexcept>
#include <algorithm>
namespace Mystack
{   
    using namespace MylistNode;
    using std::vector;
    template<typename T>
    class Mystack
    {
    private:
        int stackSize;
        ListNode<T> *stackTop;
    public:
        Mystack(/* args */);
        ~Mystack();

        int size() 
        {
            return this->stackSize;
        }

        
        bool isEmpty() 
        {
            return this->stackSize == 0;
        }

        
        void push(T val) 
        {
            ListNode<T> *node = new ListNode<T>(val);
            node->nextNode = stackTop;
            stackTop = node;
            ++stackSize;
        }

        
        T pop() 
        {
            T poped = this->top();
            ListNode<T> *tmp = this->stackTop;
            this->stackTop = this->stackTop->nextNode;
            delete tmp;
            this->stackSize--;
            return poped;
        }

       
        T top() 
        {
            if (this->isEmpty())
            {
                throw std::out_of_range("空栈");
            }
            return this->stackTop->val;
        }

        
        vector<T> toVector() 
        {
            ListNode<T> *node = this->stackTop;
            vector<T> result(this->size());
            for (int i = 0; i < result.size(); i++)
            {
                result[i] = node->val;
                node = node->nextNode;
            }
            
            return result;
            

        }
        
        
    };

    template <typename T>
    Mystack<T>::Mystack()
    {
        this->stackTop = nullptr;
        this->stackSize = 0;
    }

    template <typename T>
    Mystack<T>::~Mystack()
    {
        // freeMemoryListNode(this->stackTop);
    }

} // namespace Mystack
