#ifndef __queue__
#define __queue__ 1001

#include "linked_list.hpp"

namespace stl
{
	template <class q>
	class queue_a
	{
	protected:
		int front, rear;
		uint max;
		q *arr = 0;

	public:
		string adt_type = "Queue";
		// Constructor
		explicit queue_a(const uint &limit = 10)
		{
			front = rear = 0;
			if (limit)
			{
				max = limit;
				arr = new q[limit];
			}
			else
				std::__throw_out_of_range("QUEUE : Limit out of bounds");
		}

		explicit queue_a(const initializer_list<q> &v)
		{
			for (q i : v)
				this->enqueue(i);
		}

		// Functions
		bool empty() const
		{
			return rear == front;
		}

		bool full() const
		{
			return rear - front == max;
		}

		uint size() const
		{
			return rear - front;
		}

		uint capacity() const
		{
			return max;
		}

		void enqueue(const q &val)
		{
			chkFull(this);
			arr[(rear++) % max] = val;
		}

		q dequeue()
		{
			chkEmpty(this);
			return arr[(front++) % max];
		}

		q &Front() const
		{
			chkEmpty(this);
			return arr[front % max];
		}

		q &Back() const
		{
			chkEmpty(this);
			return arr[(rear-1) % max];
		}

		void clear()
		{
			front = rear = -1;
			delete[] arr;
			max = 0;
			arr = 0;
		}

		void swap(queue_a &l)
		{
			std::swap(this->arr, l.arr);
			std::swap(this->max, l.max);
			std::swap(this->front, l.front);
			std::swap(this->rear, l.rear);
		}

		friend ostream &operator<<(ostream &out, queue_a &st)
		{
			out << '{';
			for (int i = st.front; i < st.rear; i++)
			{
				out << st.arr[(st.max + i) % st.max];
				if (i < st.rear - 1)
					out << ", ";
			}
			out << '}';
			return out;
		}

		// Destructor
		~queue_a()
		{
			this->clear();
		}
	};

	template <typename tp>
	class queue_l
	{
	private:
		circularList<tp> c;

	public:
		// Constructor
		queue_l() {}

		// Functions
		bool empty() const
		{
			return c.empty();
		}

		uint size() const
		{
			return c.size();
		}

		tp &front() const
		{
			chkEmpty(this);
			return c.front();
		}

		tp &back() const
		{
			chkEmpty(this);
			return c.back();
		}

		void clear()
		{
			c.clear();
		}

		void enqueue(const tp &val)
		{
			c.push_back(val);
		}

		tp dequeue()
		{
			chkEmpty(this);
			tp val = this->front();
			c.pop_front();
			return val;
		}

		// Destructor
		~queue_l()
		{
			c.clear();
		}
	};
};
#endif