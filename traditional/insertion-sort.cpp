#include <cstdlib>

#pragma once
class insertionSort{
public:
	template<typename T>
	//Left iterator, Right iterator, *swap function, *comparator function
	static void sort(T *l, T *r, bool (&cmp)(T&, T&), void(&swp)(T&, T&)){
		//Assume range is valid address
		//assert(l <= r);
		
		sort_runner(l, r, cmp, swp);
		return;
	}
private:
	template<typename T>
	//le -> less than comparator
	static inline void sort_runner(T *&l, T *&r, bool (&le)(T&, T&), void(&swp)(T&, T&)){
		size_t n = r - l;

		for(size_t j = 1; j < n; j++){
			size_t i = j;
			while(i > 0 && le(*(l + i), *(l + i - 1))){
				swp(*(l + i), *(l + i - 1));
				i--;
			}
		}
	}
};