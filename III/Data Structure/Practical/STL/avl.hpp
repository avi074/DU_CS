#ifndef __avl__
#define __avl__ 

#include "bst.hpp"

using namespace std;

namespace stl
{
    template<class E>
    struct T_node
    {
        typedef T_node<E>* pointer;

        E val;
        int height = 0;
        pointer left = 0, right = 0;

        T_node(){}
        T_node(const E& v): val(v){}
    };

    template<class T>
    class avl : public BST<T, T_node<T>>
    {
    private:
        typedef BST<T, T_node<T>> _tree;
        typedef typename _tree::node node;
        typedef typename _tree::ref_ptr ref_ptr;

        using _tree::root;
        using _tree::len;

    protected:

        int height(ref_ptr p)
        {
            if(p)
                return p->height;
            return 0;
        }

        void updateHeight(ref_ptr h)
        {
            if(h)
            {
                int a = height(h->left);
                int b = height(h->right);

                h->height = 1 + (a > b ? a : b);
            }
        }

        int bal_fact(ref_ptr p)
        {
            if(p)
                return height(p->left) - height(p->right);
            return 0;
        }

        //1 for left & 0 for right
        void Rotate(ref_ptr& x, bool left)
        {
            ref_ptr a,b;

            if(left)
            {
                a = x->right;
                b = a->left;

                a->left = x;
                x->right = b;
            }
            else
            {
                a = x->left;
                b = a->right;

                a->right = x;
                x->left = b;
            }

            updateHeight(a);
            updateHeight(x);

            x = a;
        }

    public:
        // Constructors
        avl(){}

        avl(const initializer_list<T>& v):_tree(v){}

        // Functions


        // Destructor
        ~avl(){}
    };
} // namespace stl


#endif