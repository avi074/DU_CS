#ifndef __list_iterator__
#define __list_iterator__

#include <initializer_list>
#include <bits/stl_iterator_base_types.h>
#include "Exception.hpp"

using std::iterator_traits;
//#include <bits/functexcept.h>  // For functional exceptions like out_of_range, underflow_error, overflow_error & so on

template <class Tp>
struct NODE
{
    // tags for iterator
    typedef std::forward_iterator_tag iterator_category;
    typedef Tp value_type;
    typedef Tp &reference;
    typedef NODE *pointer;
    typedef int difference_type;

    // Members
    value_type val;
    pointer next = 0;

    // Constructor
    NODE() {}
    NODE(const value_type &data) : val(data) {}
    NODE(const value_type &data, pointer n) : val(data), next(n) {}
    NODE(pointer n) : next(n) {}
};

template <class T>
struct NODES
{
    // tags for iterator
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef T value_type;
    typedef T &reference;
    typedef NODES *pointer;
    typedef ptrdiff_t difference_type;
    // Members
    value_type val;
    pointer next = 0;
    pointer prev = 0;

    // Constructor
    NODES(){};
    NODES(const value_type &data) : val(data){};
};

template <typename node_ptr>
class list_iterator
{
private:
    node_ptr ptr;
    typedef typename iterator_traits<node_ptr>::value_type traits;

protected:
    void check()
    {
        if (!this->ptr)
            throw ADTExceptions("Null_Pointer_Error :\n\tIterator is pointing to null !!!");
    }

public:
    // tags
    typedef node_ptr iterator_type;
    typedef typename traits::iterator_category iterator_category;
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
        // check();
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

#ifdef DoublyList 
    // Operators for Bidirectional iterator
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
#endif
    // Destructor
    ~list_iterator()
    {
        this->ptr = 0;
    }
};

#endif