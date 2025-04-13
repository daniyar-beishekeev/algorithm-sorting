#include <cstdlib>

#include "../traditional/merge-sort.cpp"
#include "../traditional/insertion-sort.cpp"

class timSort: mergeSort{
public:
	//Merge sort, instead of copying values, swaps each 

	template<typename T>
	//Left iterator, Right iterator, *swap function, *comparator function
	static void sort(T *l, T *r, bool (&cmp)(T&, T&), void(&swp)(T&, T&)){
		//Assume range is valid address
		//assert(l <= r);

		//Allocate extra space once and reuse for each merge call
		//!Process is not parallel, so it is sufficient for allocate memory once
		T* extraSpace = new T[r - l];
		
		sort_runner(l, r, cmp, extraSpace, swp);

		delete[] extraSpace;
		return;
	}

private:
	template<typename T>
	//le -> less than comparator
	static void sort_runner(T *l, T *r, bool (&le)(T&, T&), T* &extraSpace, void(&swp)(T&, T&)){
		if(l + 1 < r){
			if(r - l <= 32){
				insertionSort::sort(l, r, le, swp);
			}else{
				//Partition range by mid
				T* mid = l + (r - l) / 2;
				sort_runner(l, mid, le, extraSpace, swp);
				sort_runner(mid, r, le, extraSpace, swp);

				merge(l, r, mid, le, extraSpace, swp);
			}
		}
		return;
	}
};