#include "SinglyList.cpp"

// Stack : LIFO (Last In First Out)
// Implementation via fixed size Dynamic Array
template <class T>
class stack_a
{
protected:
    T *arr = 0;
    int index = -1;
    uint max = 0;

public:
    const string adt_type = "STACK"; 
    //Constructor
    explicit
    stack_a(const int& limit = 10){
        if(limit < 1)
            throw ADTExceptions("STACK : Limit out of bounds");
        max = limit;
        arr = new T[max];
    }

    explicit
    stack_a(const initializer_list<T>& l){
        max = l.size();
        arr = new T[max];
        for(auto&& i:l)
            this->push(i);
    }

    //Functions
    bool empty() { return index == -1; }

    bool full() { return index == max-1; }

    virtual void push(const T& ele){
        chkFull(this);
        arr[++index] = ele;
    }

    virtual T pop(){
        chkEmpty(this);
        return arr[index--];
    }

    T& top(){
        chkEmpty(this);
        return arr[index];
    }

    int size() const {
        return index+1;
    }

    uint capacity() const {
        return max;
    }

    void swap(stack_a &s){
        std::swap(this->arr, s.arr);
        std::swap(this->index, s.index);
        std::swap(this->max, s.max);
    }

    void clear(){
        delete[] arr;
        arr = 0;
        index = -1;
        max = 0;
    }

    friend ostream& operator<<(ostream& out, stack_a& stck){
        out << '{';
        for(int i = 0; i <= stck.index; i++){
            out << stck.arr[i];
            if(i < stck.index)
                out << ", ";
        }
        out << '}';
        return out;
    }

    //Destructor
    ~stack_a(){
        clear();
    }
};

// Implementation via Singly Linked list
template<class E>
class stack_l{

    private:
        SinglyList<E> s;
    public:
        // Constructor
        stack_l(){}

        stack_l(const initializer_list<E>& v){
            s = v;
        }
        
        // Function
        bool empty() const{
            return s.empty();
        }

        void push(const E& val){
            try{ 
                s.enqueue(val);
            }
            catch(ADTExceptions e){
                throw ADTExceptions('2',"STACK");
            }
        }

        E pop(){
            if(empty())
                throw ADTExceptions('1',"STACK");
            return s.dequeue();
        }

        E& top(){
            if(empty())
                throw ADTExceptions('1',"STACK");
            return s[0];
        }

        uint size() const {
            return s.size();
        }

        void swap(stack_l& stck){
           this->s.swap(stck.s);
        }

        friend ostream& operator<<(ostream& out,const stack_l<E>& l){
            out << l.s;
            return out;
        }

        // Destructor
        ~stack_l(){
            s.clear();
        }    
};

// Implimentation via Dynamic Array in a golden ratio (1.6180339) or fibonacci series
template <typename A>
class stack_D : public stack_a<A>{

    typedef stack_a<A> stack;
    using stack::arr;
    using stack::index;
    using stack::max;

    protected:
        uint round(const float& f){
            if(f - (int)f >= 0.5)
                return f+1;
            return f;
        } 

        void resize(const uint& size){
            max = size;
            A* t = new A[max];
            for(int i = 0; i <= index; i++)
                t[i] = arr[i];
            std::swap(arr,t);
            delete[] t;
        }

    public:
    // Constructor
        stack_D():stack(1){}
        stack_D(const int& limit):stack(limit){}
        stack_D(const initializer_list<A>& v):stack(v){}

    // Functions
        void push(const A& val){
            if(stack::full()){
                resize(round(max*1.618034f));
            }
            arr[++index] = val;
        }

        A pop(){
            chkEmpty(this);
            if(index == round(max/2.0f)){
                resize(round(max/1.618034f));
            }
            return arr[index--];
        }
    // Destructor
        ~stack_D(){}
};