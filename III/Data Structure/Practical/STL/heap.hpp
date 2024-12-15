#ifndef __heap__
#define __heap__

#include "linked_list.hpp"
#include <climits>

namespace stl{

	template<class Tp, uint max = 10, class _compare = std::less<Tp> >
	class heap
	{
	private:
		Tp arr[max];
		uint index = 0;
		_compare cmp = _compare();

	protected:
		void check_i(const uint& i){
			if(i >= index)
				std::__throw_out_of_range("Heap : Index Out of Bounds !!!");
		}

		void arrange(uint i){ 
			while(i && cmp(arr[i], arr[parent(i)]))
			{
				std::swap(arr[i], arr[parent(i)]);
				i = parent(i);
			}
		}

	public:
		// Constructors
		heap(){}

		explicit heap(const heap& h){

		}

		explicit heap(const initializer_list<Tp>& l)
		{
			for(Tp i:l)
				this->insert(i);
		}

		explicit heap(heap&& h){
			this->swap(h);
		}

		//Functions
		uint parent(const uint& i){
			return (i-1)/2;
		}

		uint left(const uint& i){
			return 2*i+1;
		}

		uint right(const uint& i){
			return 2*i+2;
		}

		bool empty() const{
			return !index;
		}

		bool full() const{
			return index == max;
		}

		uint size() const{
			return index;
		}

		uint capacity() const{
			return max;
		}

		Tp getTop() const{
			chkEmpty(this);
			return arr[0];
		}

		void swap(heap& h){
			std::swap(this->arr, h.arr);
			std::swap(this->index, h.index);
		}

		void insert(const Tp& key)
		{
			chkFull(this);
			arr[index++] = key;
			arrange(index-1);
		}

		Tp extractTop(){
			chkEmpty(this);

			if(index == 1)
				return arr[--index];

			Tp val = arr[0];
			arr[0] = arr[index-1];
			index--;
			heapify(0);
			return val;
		}

		void updateKey(const uint& i, const Tp& key){
			check_i(i);
			arr[i] = key;
			arrange(i);
		}

		void deleteKey(const uint& i){
			updateKey(i, INT_MIN);
			extractTop();
		}

		void heapify(uint i){
			check_i(i);
			int l, r, top;
			bool loop;
			do
			{
				l = left(i);
				r = right(i);
				top = i;

				if(l < max && cmp(arr[l], arr[i]))
					top = l;

				if(r < max && cmp(arr[r], arr[i]))
					top = r;

				if(top != i){
					std::swap(arr[i], arr[top]);
					loop = true;
					top = i;
					//heapify(top);
				}
				else
					loop = false; 
			}while(loop);
		}

		// Operators
		friend ostream& operator<<(ostream& out, heap& h){
	        out << '{';
	        for(int i = 0; i < h.index; i++){
	            out << h.arr[i];
	            if(i < h.index-1)
	                out << ", ";
	        }
	        out << '}';
	        return out;
	    }

		// Destructor
		~heap(){}
	};
};

#endif