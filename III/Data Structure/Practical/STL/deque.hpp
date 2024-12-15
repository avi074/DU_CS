#ifndef __deque__
#define __deque__

#include "linked_list.hpp"

namespace stl
{
	template<class E>
	class deque
	{
	private:
		doublyList<E> d;

	public:
		// Constructors
		deque() {}

		deque(const initializer_list<E> &v)
		{
			d = v;
		}

		// Functions

		bool empty() const{
			return d.empty();
		}

		uint size() const{
			return d.size();
		}

		E& front() const{
			chkEmpty(this);
			return d.front();
		}

		E& back() const{
			chkEmpty(this);
			return d.back();
		}

		void swap(deque& dq){
			this->d.swap(dq.d);
		}

		void clear(){
			d.clear();
		}

		E pop_front(){
			E val = front();
			d.pop_front();
			return val;
		}

		E pop_back(){
			E val = back();
			d.pop_back();
			return val;
		}

		void push_front(const E& val){
			d.push_front(val);
		}

		void push_back(const E& val){
			d.push_back(val);
		}

		friend ostream& operator<<(ostream& out, const deque& dq)
		{
			out << dq.d;
			return out;
		}

		// Destructor
		~deque(){
			d.clear();
		}
	};
};
#endif