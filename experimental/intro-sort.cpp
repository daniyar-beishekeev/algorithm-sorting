#include <cstdlib>

#include "../traditional/quick-sort.cpp"
#include "../traditional/insertion-sort.cpp"
#include "../traditional/heap-sort.cpp"

class introSort: quickSort{
public:
	//Merge sort, instead of copying values, swaps each 

	template<typename T>
	//Left iterator, Right iterator, *swap function, *comparator function
	static void sort(T *l, T *r, bool (&cmp)(T&, T&), void(&swp)(T&, T&)){
		//Assume range is valid address
		//assert(l <= r);

		size_t n = r - l;
		short int depth = std::floor(std::log2(n)) * 2;
		sort_runner(l, r, depth, cmp, swp);

		return;
	}

private:
	template<typename T>
	//le -> less than comparator
	static void sort_runner(T *l, T *r, short int depth, bool (&le)(T&, T&), void(&swp)(T&, T&)){
		size_t n = r - l;
		if(n < 16){
			insertionSort::sort(l, r, le, swp);
			//Using of selection sort to reduce swap number
			//Insertion sort is could be less time
		}else if(depth == 0){
			//High depth reached
			heapSort::sort(l, r, le, swp);
		}else{
			T* pivot = partition(l, r, le, swp);

			depth--;
			sort_runner(l, pivot, depth, le, swp);
			sort_runner(pivot + 1, r, depth, le, swp);
		}
	}
};