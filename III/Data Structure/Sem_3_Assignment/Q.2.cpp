#include <iostream>
#include "Sem_3/stack.cpp"

using namespace std;

template<typename q,uint max = 10>
class Queue{
    private:
        stack_l<q> s1,s2;

    public:
        // Functions
        bool empty(){
            return !this->size();
        }

        bool full(){
            return this->size() == max;
        }

        uint size(){
            return s1.size()+s2.size();
        }

        uint capacity(){
            return max;
        }

        void enqueue(const q& val){
            if(this->full())
                throw overflow_error("Queue::Check(Queue is full !!!)");
            s1.push(val);
        }

        q dequeue(){
            if(this->empty())
                throw underflow_error("Queue::Check(Queue is empty !!!)");

            if(s2.empty())
                while(!s1.empty())
                    s2.push(s1.pop());
            return s2.pop();
        }

        void detail(){
            cout << boolalpha << "\nQueue is empty\t  : " << this->empty();
            cout << "\nQueue is full\t  : " << this->full();
            cout << "\nSize of Queue\t  : " << this->size();
            cout << "\nCapacity of Queue : " << this->capacity() << endl << endl;
        }
};



int main(){
    Queue<int,5> q1;

    cout << "\nAfter creation, Queue Details : \n";
    q1.detail();

    for(int i = 1; i <= 5; i++)
        q1.enqueue(5*i);

    cout << "\nAfter enqueuing, Queue Details : \n";
    q1.detail();

    cout << "\nYour Queue : ";
    while(!q1.empty())
        cout << q1.dequeue() << ' ';
    
    cout << "\n\nAfter dequeuing, Queue Details : ";
    q1.detail();

}