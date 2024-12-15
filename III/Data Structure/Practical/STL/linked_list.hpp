#ifndef _linked_list_
#define _linked_list_ 1011

#include <initializer_list>
#include "list_iterator.hpp"
#include "functions.hpp"

using namespace std;
namespace stl
{
template <class node_c>
class list_base
{
public:
    typedef node_c node;
    typedef typename node::value_type T;
    typedef typename node::pointer ref_ptr;
    typedef list_iterator<ref_ptr> iterator;

protected:
    // Data members
    ref_ptr head = 0;
    ref_ptr tail = 0;
    uint len = 0;

    // Functions
    uint &length()
    {
        return len;
    }

    void check_i(const uint &i)
    {
        if (i >= len)
            std::__throw_out_of_range("List::Check(Index Out of Bounds)");
    }

    virtual ref_ptr nodeAt(const uint &i) = 0;

public:
    // Constructors
    list_base() {}

    // Functions regarding Location

    T &at(const uint &index)
    {
        return nodeAt(index)->val;
    }

    int indexOf(const T &data) const
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

    T &front() const
    {
        chkEmpty(this);
        return this->head->val;
    }

    T &back() const
    {
        chkEmpty(this);
        return this->tail->val;
    }

    // Iterative Functions

    iterator begin() const
    {
        return iterator(head);
    }

    virtual iterator end() const
    {
        return iterator();
    }

    iterator iterAt(const uint &i)
    {
        return iterator(this->nodeAt(i));
    }

    // Basic Funcions
    bool empty() const
    {
        return !this->head;
    }

    uint size() const
    {
        return len;
    }

    void reset()
    {
        head = 0;
        len = 0;
        tail = 0;
    }

    // Insertion Functions

    virtual void push_front(const T &val) = 0;

    virtual void push_back(const T &val) = 0;

    virtual void insert(const uint &pos, const T &val) = 0;

    // Deletion Functions

    virtual void pop_front() = 0;

    virtual void pop_back() = 0;

    virtual void remove_i(const uint &pos) = 0;

    virtual bool remove(const T &val) = 0;

    /* @_Clear
     * check head != null
     * create tmp ref_ptr*(node**) & set to location of head
     * traverse head to its next pointer untill head != null
     * delete *tmp
     * set *tmp to NULL
     * set tmp to head's location
     * reset the parameters
     */
    virtual void clear()
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

    // Other Functions

    virtual void reverse() = 0;

    bool search(const T &data) const
    {
        return this->indexOf(data) != -1;
    }

    void swap(list_base &d)
    {
        std::swap(this->len, d.len);
        std::swap(this->head, d.head);
        std::swap(this->tail, d.tail);
    }

    void append(const list_base &l1)
    {
        if (!l1.head)
            return;
        else
            copy(l1.begin(), l1.end(), this);
    }

    void append(const initializer_list<T>& l)
    {
        copy(l.begin(), l.end(), this);
    }

    // Operators
    T &operator[](const uint &idx)
    {
        return nodeAt(idx)->val;
    }

    void operator=(const list_base &s)
    {
        this->clear();
        this->append(s);
    }

    void operator=(const initializer_list<T>& l)
    {
        this->clear();
        copy(l.begin(), l.end(), this);
    }

    void operator+=(const list_base &s)
    {
        this->append(s);
    }

    void operator+=(const initializer_list<T> &s)
    {
        this->append(s);
    }

    friend ostream &operator<<(ostream &out, const list_base &s)
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

    friend istream &operator>>(istream &in, list_base &l)
    {
        T val;
        in >> val;
        l.push_back(val);
        return in;
    }

    void operator>>(const T &val)
    {
        this->push_back(val);
    }

    // Destructor
    virtual ~list_base()
    {
        this->clear();
    }
};

// Singly List
template <class Tp>
class singlyList : public list_base<node_s<Tp>>
{
private:
    typedef list_base<node_s<Tp>> _list;

    typedef typename _list::node node;

    typedef typename _list::ref_ptr ref_ptr;


    using _list::check_i;
    using _list::head;
    using _list::len;
    using _list::tail;

protected:
    ref_ptr nodeAt(const uint &index)
    {
        check_i(index);

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

public:
    typedef typename _list::iterator iterator;
    // Constructors

    singlyList() {}

    singlyList(ref_ptr p)
    {
        if (p)
        {
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
    }

    singlyList(const initializer_list<Tp> &v)
    {
        copy(v.begin(), v.end(), this);
    }

    singlyList(const singlyList &s)
    {
        this->append(s);
    }

    // Insertion Functions

    void push_front(const Tp &val)
    {
        if (!head)
        {
            head = new node(val);
            tail = head;
        }
        else
        {
            ref_ptr tmp = new node(val, head);
            head = tmp;
        }
        len++;
    }

    void push_back(const Tp &val)
    {
        if (!head)
            push_front(val);
        else
        {
            tail->next = new node(val);
            tail = tail->next;
            len++;
        }
    }

    void insert(const uint &pos, const Tp &val)
    {
        if (!pos)
            this->push_front(val);
        else if (pos == len - 1)
            this->push_back(val);
        else
        {
            ref_ptr t = nodeAt(pos - 1);
            ref_ptr n = new node(val, t->next);
            t->next = n;
            len++;
        }
    }

    // Deletion Functions

    void pop_front()
    {
        chkEmpty(this);
        ref_ptr h = head;
        head = head->next;
        delete h;
        len--;
    }

    void pop_back()
    {
        chkEmpty(this);
        if (len == 1)
            pop_front();
        else
        {
            ref_ptr t = tail;
            tail = nodeAt(len - 2);
            tail->next = 0;
            delete t;
            len--;
        }
    }

    void remove_i(const uint &pos)
    {
        if (!pos)
            this->pop_front();
        else if (pos == len - 1)
            this->pop_back();
        else
        {
            ref_ptr t = nodeAt(pos - 1);
            ref_ptr n = t->next;
            t->next = n->next;
            delete n;
            len--;
        }
    }

    bool remove(const Tp &val)
    {
        ref_ptr n = head;
        bool erased = false;
        if (n)
        {
            ref_ptr p = n;

            while (n)
            {
                if (n->val == val)
                {
                    erased = true;
                    break;
                }
                p = n;
                n = n->next;
            }

            if (erased)
                if (p == n)
                    this->pop_front();
                else
                {
                    if (!n->next)
                        this->tail = p;
                    p->next = n->next;
                    len--;
                }
        }
        return erased;
    }

    // Other Function

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

    // Operator
    singlyList operator+(const singlyList &s) const
    {
        singlyList tmp(*this);
        tmp.append(s);
        return (tmp);
    }
};

// Doubly List
template <class T>
class doublyList : public list_base<node_d<T>>
{
private:
    typedef list_base<node_d<T>> list;

    typedef typename list::node node;

    typedef typename list::ref_ptr ref_ptr;

    using list::check_i;
    using list::head;
    using list::len;
    using list::tail;

protected:
    ref_ptr nodeAt(const uint &pos)
    {
        check_i(pos);

        if (!pos)
            return head;
        else if (pos == len - 1)
            return tail;
        else
        {
            ref_ptr tmp = 0;
            uint i;

            if (pos < len / 2)
            {
                tmp = head->next;
                i = 1;
            }
            else
            {
                tmp = tail->prev;
                i = len - 2;
            }

            for (bool firstHalf = (i < (len / 2)); i != pos;)
            {
                if (firstHalf)
                {
                    tmp = tmp->next;
                    i++;
                }
                else
                {
                    tmp = tmp->prev;
                    i--;
                }
            }
            return tmp;
        }
    }

public:
    typedef typename list::iterator iterator;
    // Constructors

    doublyList() {}

    doublyList(const initializer_list<T> &v)
    {
        copy(v.begin(), v.end(), this);
    }

    doublyList(doublyList &s)
    {
        this->append(s);
    }

    // Insertion Functions

    void push_front(const T &val)
    {
        if (!head)
        {
            head = new node(val);
            tail = head;
        }
        else
        {
            head->prev = new node(val, head);
            head = head->prev;
        }
        len++;
    }

    void push_back(const T &val)
    {
        if (!head)
            push_front(val);
        else
        {
            tail->next = new node(val, tail, 0);
            tail = tail->next;
            len++;
        }
    }

    void insert(const uint &pos, const T &val)
    {
        check_i(pos);
        if (!pos)
            push_front(val);
        else if (pos == len - 1)
            push_back(val);
        else
        {
            ref_ptr ptr = nodeAt(pos);
            ref_ptr p = new node(val, ptr->prev, ptr);
            ptr->prev->next = p;
            ptr->prev = p;
            len++;
        }
    }

    // Deletion Functions

    void pop_front()
    {
        chkEmpty(this);
        ref_ptr h = head;
        head = head->next;
        if (head)
            head->prev = 0;
        delete h;
        len--;
    }

    void pop_back()
    {
        chkEmpty(this);
        if (len == 1)
            this->pop_front();
        else
        {
            ref_ptr t = tail;
            tail = tail->prev;
            tail->next = 0;
            delete t;
            len--;
        }
    }

    void remove_i(const uint &pos)
    {
        chkEmpty(this);
        if (!pos)
            this->pop_front();
        else if (pos == len - 1)
            this->pop_back();
        else
        {
            ref_ptr p = nodeAt(pos);
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
            len--;
        }
    }

    bool remove(const T &val)
    {
        chkEmpty(this);
        ref_ptr h = this->head;
        bool del = 0;
        while (h)
        {
            if (h->val == val)
            {
                h->prev->next = h->next;
                h->next->prev = h->prev;
                del = 1;
                break;
            }
            h = h->next;
        }
        if (del)
        {
            delete h;
            len--;
        }
        return del;
    }

    // Other Function
    void reverse()
    {
        if (head)
        {
            ref_ptr tmp = this->head;
            ref_ptr tmp1 = this->tail;

            while (tmp != tmp1 && tmp->prev != tmp1)
            {
                swap(tmp->val, tmp1->val);
                tmp = tmp->next;
                tmp1 = tmp1->prev;
            }
        }
    }
};

// Circular List
template <class T>
class circularList : public list_base<node_s<T>>
{
private:
    typedef list_base<node_s<T>> list;

    typedef typename list::node node;

    typedef typename list::ref_ptr ref_ptr;

    using list::check_i;
    using list::head;
    using list::tail;
    using list::len;

protected:
    ref_ptr nodeAt(const uint &index)
    {
        check_i(index);

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

public:
    typedef typename list::iterator iterator;
    // Constructors

    circularList() {}

    circularList(const initializer_list<T> &v)
    {
        copy(v.begin(), v.end(), this);
    }

    circularList(circularList &s)
    {
        this->append(s);
    }

    //
    iterator end() const
    {
        return iterator(this->tail);
    }

    // Insertion Functions

    void push_front(const T &val)
    {
        if (!head)
        {
            head = new node(val);
            tail = head;
            head->next = tail;
        }
        else
        {
            ref_ptr t = new node(val, head);
            tail->next = t;
            head = t;
        }
        len++;
    }

    void push_back(const T &val)
    {
        if (!head)
            push_front(val);
        else
        {
            ref_ptr t = new node(val, tail->next);
            tail->next = t;
            tail = t;
            len++;
        }
    }

    void insert(const uint &pos, const T &val)
    {
        check_i(pos);
        if (!pos)
            push_front(val);
        else if (pos == len - 1)
            push_back(val);
        else
        {
            ref_ptr t = nodeAt(pos - 1);
            ref_ptr n = new node(val, t->next);
            t->next = n;
        }
    }

    // Deletion Functions

    void pop_front()
    {
        chkEmpty(this);
        ref_ptr h = this->head;
        if (len == 1)
        {
            tail = 0;
            head = 0;
        }
        else
        {
            head = h->next;
            tail->next = head;  
        }
        delete h;
        len--;
    }

    void pop_back()
    {
        chkEmpty(this);
        if (len == 1)
            this->pop_front();
        else
        {
            ref_ptr t = nodeAt(len - 2);
            t->next = tail->next;
            delete tail;
            tail = t;
            len--;
        }
    }

    void remove_i(const uint &pos)
    {
        chkEmpty(this);
        if (!pos)
            this->pop_front();
        else if (pos == len - 1)
            this->pop_back();
        else
        {
            ref_ptr t = nodeAt(pos - 1);
            ref_ptr n = t->next;
            t->next = n->next;
            delete n;
            len--;
        }
    }

    bool remove(const T &val)
    {
        ref_ptr n = head;
        bool erased = false;
        if (n)
        {
            ref_ptr p = n;

            do
            {
                p = n;
                if (n->val == val)
                {
                    erased = true;
                    break;
                }
                n = n->next;
            } while (n != head);

            if (erased)
                if (p == n)
                    this->pop_front();
                else
                {
                    if (n->next = head)
                        this->tail = p;
                    p->next = n->next;
                    len--;
                }
        }
        return erased;
    }

    // Other Function

    void clear()
    {
        if (head)
        {
            tail->next = 0;
            list::clear();
        }
    }

    void append(const circularList &s)
    {
        if (s.head)
        {
            ref_ptr h = s.head;
            do
            {
                this->push_back(h->val);
                h = h->next;
            } while (h != s.head);
        }
    }

    void reverse()
    {
        if (!head || len == 1)
            return;
        else
        {
            ref_ptr p = 0, n = 0, c = this->head;

            do
            {
                n = c->next;
                c->next = p;
                p = c;
                c = n;
            } while (c != head);
            head->next = p;
            std::swap(head, tail);
        }
    }

    // Operator
    friend ostream &operator<<(ostream &out, const circularList &s)
    {
        out << '{';
        ref_ptr h = s.tail;
        if (h)
            do
            {
                h = h->next;
                out << h->val;
                if (h != s.tail)
                    out << ", ";
            } while (h != s.tail);
        out << '}';
        return out;
    }
};
};
#endif
