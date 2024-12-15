#ifndef __BST__
#define __BST__

#include "queue.hpp"
#include "stack.hpp"

namespace stl
{
// Tnode = Tree Node
template <typename N>
struct Tnode
{
	typedef Tnode<N>* pointer;

	N val;
	pointer left = 0, right = 0;

	// Constructor
	Tnode() {}
	Tnode(const N &val) : val(val) {}
};

template<class T, class node_c = Tnode<T>>
class BST
{
public:
	typedef node_c node;
	typedef typename node::pointer ref_ptr;

protected:
	ref_ptr root = 0;
	uint len = 0;

	ref_ptr* nodeOf(const T &v)
	{
		ref_ptr* p = 0;

		if (root)
		{
			p = &root;
			while ((*p)->val != v)
			{
				if (v > (*p)->val)
					p = &(*p)->right;
				else
					p = &(*p)->left;

				if (!(*p))
					return NULL;
			}
		}
		return p;
	}

	// Morris Algorithm
	// True for in-order & False for pre-order Traversal
	void morris(bool b, ostream_iterator<T> o = ostream_iterator<T>(std::cout, "\t")) const
	{
		chkEmpty(this);
		ref_ptr c = root, p = 0;

		while (c)
		{
			if (!c->left)
			{
				o = c->val;
				c = c->right;
			}
			else
			{
				p = c->left;
				while (p->right && p->right != c)
					p = p->right;

				if (p->right)
				{
					p->right = 0;
					if (b)
						o = c->val;
					c = c->right;
				}
				else
				{
					p->right = c;
					if (!b)
						o = c->val;
					c = c->left;
				}
			}
		}
	}

	void insert(const T &data, ref_ptr &p) // Recursive approach
	{
		if (p == 0)
			p = new Tnode<T>(data);
		else if (data > p->val)
			insert(data, p->right);
		else
			insert(data, p->left);
	}

	void delete_tree(ref_ptr* p)
	{
		if (*p)
		{
			delete_tree(&(*p)->left);
			delete_tree(&(*p)->right);
			delete *p;
			*p = 0;
		}
	}

	//Delete Program
	void delNode(const T& v, bool merge)
	{
		chkEmpty(this);
		ref_ptr* c = nodeOf(v);
		ref_ptr tmp = *c, prev = 0;

		if (*c)
		{
			// Case : Single Child
			if (!tmp->left)
				*c = tmp->right;
			else if (!tmp->right)
				*c = tmp->left;

			// Case : Two children
			else
			{
				prev = tmp;
				tmp = (*c)->left;

				while (tmp->right) {
					prev = tmp;
					tmp = tmp->right;
				}

				if (merge) // Deletion via Merging
				{
					tmp->right = (*c)->right;
					tmp = *c;
					*c = (*c)->left;
				}
				else  	// Deletion via Copying
				{
					(*c)->val = tmp->val;
					if (prev == (*c))
						(*c)->left = tmp->left;
					else
						prev->right = tmp->left;
				}
			}
		}
		delete tmp;
		len--;
	}


public:
	// Constructor
	BST() {}
	BST(ref_ptr *r) : root(*r) {len++;}

	explicit
	BST(const BST &b) // Copy Constructor
	{
		this->root = b.root;
	}

	explicit
	BST(BST &&b) // Move Constructor
	{
		this->swap(b);
	}

	explicit
	BST(const initializer_list<T> &v)
	{
		for (T i : v)
			this->insert(i);
	}

	// Functions
	bool empty() const
	{
		return !root;
	}

	uint nodes_len() const
	{
		return len;
	}

	ref_ptr getRoot() const
	{
		return this->root;
	}

	T root_val() const
	{
		return root->val;
	}

	// Insertion Function
	void insert(const T &data) // Iterative approach
	{
		ref_ptr *p = &root;
		while (*p)
		{
			if (data > (*p)->val)
				p = &(*p)->right;
			else
				p = &(*p)->left;
		}
		*p = new node(data);
		len++;
	}

	void insert_r(const T &data) // Recursive approach
	{
		insert(data, this->root);
		len++;
	}

	// Traversals

	// DFT = Depth First Traversal

	// DFT in_order traversal { LVR (Left, Root(V), Right) }

	void in_trav() const// Iterative approach / Morris Algorithm
	{
		morris(1);
	}

	// DFT pre_order traversal { VLR (Root(V), Left, Right) }

	void pre_trav() const // Iterative approach
	{
		morris(0);
	}

	// DFT post_order traversal { LRV (Left, Right, Root(V)) }

	void post_trav(ostream_iterator<T> o = ostream_iterator<T>(std::cout, "\t")) const
	{
		if (root)
		{
			stack_l<ref_ptr> s;
			ref_ptr p = root, q = root;

			while (p)
			{
				for (; p->left; p = p->left)
					s.push(p);

				while (!p->right || p->right == q)
				{
					o = p->val;
					q = p;
					if (s.empty())
						return;
					p = s.pop();
				}
				s.push(p);
				p = p->right;
			}
		}


	}

	// BFT = Breadth First Traversal (level by level traversal)
	void level_trav(ostream_iterator<T> o = ostream_iterator<T>(std::cout, "\t")) const// Iterative approach
	{
		chkEmpty(this);
		queue_l<ref_ptr> q;
		ref_ptr p = 0;

		q.enqueue(root);
		while (!q.empty())
		{
			p = q.dequeue();
			o = p->val;

			if (p->left)
				q.enqueue(p->left);
			if (p->right)
				q.enqueue(p->right);
		}
	}

	void del_merge(const T &v)
	{
		delNode(v, 1);
	}

	void del_copy(const T &v)
	{
		delNode(v, 0);
	}

	void mirror()
	{
		chkEmpty(this);
		queue_l<ref_ptr> q;
		ref_ptr p = root;

		q.enqueue(p);
		while (!q.empty())
		{
			p = q.dequeue();
			std::swap(p->left, p->right);
			if (p->left)
				q.enqueue(p->left);
			if (p->right)
				q.enqueue(p->right);
		}
	}

	void del_subTree(const T &v)
	{
		chkEmpty(this);
		ref_ptr *c = nodeOf(v);
		if (c == 0)
			std::__throw_logic_error("NODE is not avaliable !!!");
		else if (*c == root || (!(*c)->right && !(*c)->left))
			std::__throw_logic_error(" Only Sub-tree can be deleted !!!");
		delete_tree(c);
	}

	// Clearing the tree
	void clear()
	{
		delete_tree(&root);
		len = 0;
	}

	// Searching in a tree
	bool search(const T &data)
	{
		chkEmpty(this);
		return nodeOf(data) != NULL;
	}

	// Swaping two trees
	void swap(BST &b)
	{
		std::swap(this->root, b.root);
		std::swap(this->length, b.length);
	}

	// Operators
	bool operator==(const BST& bst)
	{
		if (this->root && bst.root)
		{
			if (this->len != bst.len)
				return false;

			queue_l<ref_ptr> q, q1;
			ref_ptr a, b;

			q.enqueue(root);
			q1.enqueue(bst.root);

			while (!q.empty())
			{
				a = q.dequeue();
				b = q1.dequeue();

				if (a->val == b->val)
				{
					if (a->left)
						q.enqueue(a->left);
					if (a->right)
						q.enqueue(a->right);

					if (b->left)
						q1.enqueue(b->left);

					if (b->right)
						q1.enqueue(b->right);
				}
				else
					return 0;
			}
			return true;
		}
		return false;
	}

	void operator+=(const initializer_list<T>& v)
	{
		for (T i : v)
			this->insert(i);
	}

	// Destructor
	virtual ~BST()
	{
		clear();
	}
};

template<class Tp>
void in_DFT(Tnode<Tp>* p)
{
	if (p) {
		in_DFT(p->left);
		cout << p->val << '\t';
		in_DFT(p->right);
	}
}

template<class Tp>
void pre_DFT(Tnode<Tp>* p)
{
	if (p) {
		cout << p->val << '\t';
		pre_DFT(p->left);
		pre_DFT(p->right);
	}
}

template<class Tp>
void post_DFT(Tnode<Tp>* p)
{
	if (p) {
		post_DFT(p->left);
		post_DFT(p->right);
		cout << p->val << '\t';
	}
}

template<class Tp>
void BFT(Tnode<Tp>* p) // Recursive approach
{
	static queue_l<Tnode<Tp>*> q;
	if (p)
	{

		cout << p->val << '\t';
		if (p->left)
			q.enqueue(p->left);

		if (p->right)
			q.enqueue(p->right);

		if (!q.empty())
			BFT(q.dequeue());
	}
}

template<class T>
int height(Tnode<T>* h) {
	if (h)
	{
		int l = height(h->left);
		int r = height(h->right);

		/* use the larger one */
		if (l > r)
			return (l + 1);
		else return (r + 1);
	}
	else
		return -1;
}

template<class T>
int countLeaf(Tnode<T>* p)
{
	if (!p)
		return 0;

	else if (!p->left && !p->right)
		return 1;

	else
		return countLeaf(p->left) + countLeaf(p->right);
}

// template<class T>



};

#endif