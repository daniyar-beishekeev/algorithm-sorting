#include <cstdlib>

class mergeSort{
public:
	//Merge sort, instead of copying values, swaps each 

	template<typename T>
	//Left iterator, Right iterator, *swap function, *comparator function
	static void sort(T *l, T *r, bool (&cmp)(T&, T&)){
		//Assume range is valid address
		//assert(l <= r);

		//Allocate extra space once and reuse for each merge call
		//!Process is not parallel, so it is sufficient for allocate memory once
		T* extraSpace = new T[r - l];
		
		sort_runner(l, r, cmp, extraSpace);

		delete[] extraSpace;
		return;
	}

private:
	template<typename T>
	//le -> less than comparator
	static void sort_runner(T *l, T *r, bool (&le)(T&, T&), T* &extraSpace){
		if(l + 1 < r){
			//Partition range by mid
			T* mid = l + (r - l) / 2;
			sort_runner(l, mid, le, extraSpace);
			sort_runner(mid, r, le, extraSpace);

			merge(l, r, mid, le, extraSpace);
		}
		return;
	}

	template<typename T>
	static inline void merge(T *&l, T *&r, T *&mid, bool (&le)(T&, T&), T* &extraSpace){
		//MERGE PROCEDURE
		T *p1 = l, *p2 = mid;
		T *pivot = extraSpace;
		while(p1 != mid && p2 != r){
			if(le(*p1, *p2)){
				std::swap(*p1, *pivot);
				p1++;
				pivot++;
			}else{
				std::swap(*p2, *pivot);
				p2++;
				pivot++;
			}
		}
		while(p1 != mid){
			std::swap(*p1, *pivot);
			p1++;
			pivot++;
		}
		while(p2 != r){
			std::swap(*p2, *pivot);
			p2++;
			pivot++;
		}

		p2 = r;
		while(p2 != l){
			pivot--;
			p2--;
			std::swap(*pivot, *p2);
		}
		return;
	}
};