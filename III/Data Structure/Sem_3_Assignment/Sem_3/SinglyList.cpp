#include "list_iterator.hpp"

template <class T>
class SinglyList
{
private:
    typedef NODE<T> node;
    typedef typename node::pointer ref_ptr;

    uint len = 0;
    ref_ptr head = 0;
    ref_ptr tail = 0;

protected:
    void check(const uint &index)
    {
        if (index >= len)
            throw ADTExceptions("SinglyList::check(IndexOutOfBounds)");
    }

    ref_ptr nodeAt(const uint &index)
    {
        // check();
        // check(index);

        if (!index)
            return head;
        else if (index == len - 1)
            return tail;
        else
        {
            ref_ptr temp = head->next;
            for (int i = 1; i != index; i++)
                temp = temp->next;
            return temp;
        }
    }

    void copy(const initializer_list<T> &list)
    {
        for (auto a = list.begin(); a != list.end(); a++)
            this->push(*a);
    }

    void copy(const SinglyList &s)
    {
        for (auto a = s.begin(); a != s.end(); ++a)
            this->push(*a);
    }

public:
    typedef list_iterator<ref_ptr> iterator;

    // Constructor
    SinglyList(){};

    SinglyList(ref_ptr p)
    {
        if (!p)
            return;
        head = p;
        ref_ptr tmp = p;
        while (tmp->next)
        {
            tmp = tmp->next;
            len++;
        }
        tail = tmp;
        len++;
    }

    SinglyList(const initializer_list<T> &list)
    {
        copy(list);
    }

    /*  @Copy Constructor   */
    SinglyList(SinglyList &s)
    {
        copy(s);
    }

    // Iterators

    iterator begin()
    {
        return iterator(this->head);
    }

    iterator end()
    {
        return iterator();
    }

    iterator iteratorAt(const int &index)
    {
        return iterator(nodeAt(index));
    }

    // Functions
    uint size() const
    {
        return len;
    }

    bool empty() const
    {
        return !head;
    }

    T &at(const uint &index)
    {
        return nodeAt(index)->val;
    }

    int indexOf(const T &data)
    {
        ref_ptr b = this->head;

        for (int i = 0; i < this->len; i++)
        {
            if (b->val == data)
                return i;
            b = b->next;
        }
        return -1;
    }

    void insert(const uint &pos, const T &data)
    {
        check(pos);
        if (!pos)
            this->enqueue(data);
        else if (pos == len - 1)
            this->push(data);
        else
        {
            ref_ptr p = nodeAt(pos - 1);
            ref_ptr tmp = p->next;
            p->next = new node(data, tmp);
            // p->next->next = tmp;
            len++;
        }
    }

    T front()
    {
        // check();
        return this->head->val;
    }

    T back()
    {
        // check();
        return this->tail->val;
    }

    void enqueue(const T &val)
    {
        if (!head)
        {
            head = new node(val);
            tail = head;
        }
        else
        {
            ref_ptr tmp = new node(val, head);
            if (!tmp)
                throw ADTExceptions('2', "SinglyList");
            head = tmp;
        }
        len++;
    }

    T dequeue()
    {
        // check();
        ref_ptr del = head;
        T val = del->val;
        head = del->next;
        delete del;
        len--;
        return val;
    }

    void push(const T &data)
    {
        if (!head)
            enqueue(data);
        else
        {
            tail->next = new node(data);
            if (!tail->next)
                throw ADTExceptions('2', "SinglyList");
            tail = tail->next;
            len++;
        }
    }

    T pop()
    {
        // check();
        T val = tail->val;
        ref_ptr nod = tail;
        if (len > 1)
        {
            tail = nodeAt(size() - 2);
            tail->next = 0;
        }
        else
            head = 0;
        delete nod;
        len--;
        return val;
    }

    void reverse()
    {
        if (!head || len == 1)
            return;

        else
        {
            ref_ptr l = head;
            ref_ptr m = head->next;
            ref_ptr f = head->next->next;

            while (f != m)
            {
                m->next = l;
                l = m;
                m = f;
                if (f)
                    f = f->next;
            }
            tail = head;
            head = l;
            tail->next = 0;
        }
    }

    /* @Clear
     * check head != null
     * create tmp ref_ptr*(node**) & set to location of head
     * traverse head to its next pointer untill head != null
     * delete *tmp
     * set *tmp to NULL
     * set tmp to head's location
     * update length = 0
     */
    void clear()
    {
        if (head)
        {
            ref_ptr *tmp = &head;
            while (head)
            {
                head = head->next;
                delete *tmp;
                *tmp = 0;
                tmp = &head;
            }
            reset();
        }
    }

    void reset()
    {
        this->head = this->tail = 0;
        this->len = 0;
    }

    void swap(SinglyList &d)
    {
        std::swap(this->len, d.len);
        std::swap(this->head, d.head);
        std::swap(this->tail, d.tail);
    }

    bool search(const T &data)
    {
        return this->indexOf(data) != -1;
    }

    void erase_idx(const uint &index)
    {
        // check(index);
        if (index == 0)
            this->dequeue();
        else if (index == len - 1)
            this->pop();
        else
        {
            ref_ptr t = nodeAt(index - 1);
            ref_ptr del = t->next;
            t->next = del->next;
            delete del;
            len--;
        }
    }

    bool erase(const T &data)
    {
        ref_ptr n = head;
        bool erased = false;
        if (n)
        {
            ref_ptr p = n;
            while (n)
            {
                if (n->val == data)
                {
                    erased = true;
                    if (!n->next)
                        this->tail = p;
                    p->next = n->next;
                    len--;
                    break;
                }
                p = n;
                n = n->next;
            }
        }
        return erased;
    }

    /* void erase(const uint &startPos, const uint &endPos)
     {
     }*/

    void
    append(const SinglyList &l1)
    {
        if (!l1.head || !this->head)
            return;
        this->tail->next = l1.head;
        this->tail = l1.tail;
        this->len += l1.len;
    }

    void append(SinglyList &&l1)
    {
        append(l1);
        l1.reset();
    }

    // Operators
    T &operator[](const uint &idx)
    {
        return nodeAt(idx)->val;
    }

    void operator=(const initializer_list<T> &list)
    {
        this->clear();
        copy(list);
    }

    void operator=(const SinglyList &s)
    {
        this->clear();
        copy(s);
    }

    void operator=(SinglyList &&s)
    {
        this->clear();
        this->swap(s);
    }

    SinglyList &&operator+(const SinglyList &list)
    {
        return move(SinglyList(*this).operator+=(list));
    }

    void operator+=(const SinglyList &s)
    {
        copy(s);
    }

    void operator+=(SinglyList &&s)
    {
        if (!this->head)
            this->swap(s);
        else
            this->append(s);
    }

    friend ostream &operator<<(ostream &out, const SinglyList &s)
    {
        out << '{';
        ref_ptr h = s.head;
        while (h)
        {
            out << h->val;
            if (h != s.tail)
                out << ", ";
            h = h->next;
        }
        out << '}';
        return out;
    }

    // Destructor
    ~SinglyList()
    {
        clear();
    }
};
/*
template <class T>
struct Iterator
{
    // tags
    using __iterator_category = forward_iterator_tag;
    using difference_type = ptrdiff_t;
    using value_type = T;
    using pointer = ref_ptr;
    using reference = T &;

    // constructor
    Iterator() : ptr(0) {}
    Iterator(pointer p) : ptr(p) {}

    // operators
    reference operator*()
    {
        return ptr->val;
    }

    pointer base()
    {
        return this->ptr;
    }

    Iterator operator++()
    {
        this->ptr = this->ptr->next;
        return *this;
    }

    Iterator operator++(int)
    {
        Iterator tmp = *this;
        this->ptr = this->ptr->next;
        return tmp;
    }

    void operator=(const Iterator &I)
    {
        this->ptr = I.ptr;
    }

    void operator=(const pointer p)
    {
        this->ptr = p;
    }

    friend bool operator==(const Iterator &I, const Iterator &I1) noexcept
    {
        return I.ptr == I1.ptr;
    }

    friend bool operator!=(const Iterator &I, const Iterator &I1) noexcept
    {
        return I.ptr != I1.ptr;
    }

private:
    pointer ptr;
};*/