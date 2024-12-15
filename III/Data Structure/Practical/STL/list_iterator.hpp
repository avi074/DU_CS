#ifndef _list_iter_
#define _list_iter_ 1

#include <iterator>

using std::iterator_traits;

namespace stl
{
    template <class T>
    struct node_s
    {
        typedef std::forward_iterator_tag __iterator_category;
        typedef T value_type;
        typedef T &reference;
        typedef node_s *pointer;
        typedef ptrdiff_t difference_type;

        value_type val;
        pointer next = 0;

        // Constuctors
        node_s() {}
        node_s(const value_type &v) : val(v) {}
        node_s(const value_type &v, pointer n) : val(v), next(n) {}
    };

    template <class s>
    struct node_d 
    {
        typedef std::bidirectional_iterator_tag __iterator_category;
        typedef s value_type;
        typedef s &reference;
        typedef node_d *pointer;
        typedef ptrdiff_t difference_type;

        value_type val;
        pointer next = 0;
        pointer prev = 0;

        // Constuctors
        node_d() {}
        node_d(const value_type &v) : val(v) {}
        node_d(const value_type &v, pointer n) : val(v), next(n) {}
        node_d(const value_type &v, pointer p, pointer n) : val(v), prev(p), next(n) {}
    };

    template <typename node_ptr>
    class list_iterator
    {
    protected:
        node_ptr ptr;
        typedef typename iterator_traits<node_ptr>::value_type traits;

        void check()
        {
            if (!ptr)
                std::__throw_logic_error("Null_Pointer_Error :\n\tIterator is pointing to null !!!");
        }

    public:
        // tags
        typedef node_ptr iterator_type;
        typedef typename traits::__iterator_category __iterator_category;
        typedef typename traits::value_type value_type;
        typedef typename traits::difference_type difference_type;
        typedef typename traits::reference reference;
        typedef typename traits::pointer pointer;

        // constructor
        list_iterator() : ptr(0) {}

        list_iterator(node_ptr p) : ptr(p) {}

        list_iterator(const list_iterator &l) noexcept
        {
            ptr = l.ptr;
        }

        // Operators for Forward iterator
        list_iterator &operator++()
        {
            check();
            this->ptr = this->ptr->next;
            return *this;
        }

        list_iterator operator++(int)
        {
            check();
            list_iterator tmp = *this;
            this->ptr = this->ptr->next;
            return tmp;
        }

        list_iterator operator+(const uint &pos)
        {
            list_iterator tmp = *this;
            for (uint i = 0; i < pos; i++)
                ++tmp;
            return tmp;
        }

        // Operators for Backward iterator
        list_iterator &operator--()
        {
            check();
            this->ptr = this->ptr->prev;
            return *this;
        }

        list_iterator operator--(int)
        {
            check();
            list_iterator tmp = *this;
            this->ptr = this->ptr->prev;
            return tmp;
        }

        list_iterator operator-(const uint &pos)
        {
            list_iterator tmp = *this;
            for (uint i = 0; i < pos; i++)
                --tmp;
            return tmp;
        }

        node_ptr operator->() const noexcept
        {
            return this->ptr;
        }

        const node_ptr base() const noexcept
        {
            return this->ptr;
        }

        reference operator*() const noexcept
        {
            return this->ptr->val;
        }

        void operator=(const list_iterator &I)
        {
            this->ptr = I.ptr;
        }

        void operator=(const pointer p)
        {
            this->ptr = p;
        }

        bool operator==(const list_iterator &l) noexcept
        {
            return this->ptr == l.ptr;
        }

        bool operator!=(const list_iterator &l) noexcept
        {
            return this->ptr != l.ptr;
        }
        // Destructor
        ~list_iterator()
        {
            this->ptr = 0;
        }
    };
};
#endif