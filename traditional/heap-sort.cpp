#include <cstdlib>

#pragma once
class heapSort{
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

		
		//2i + 1 <= n - 1
		for(ssize_t i = (n >> 1) - 1; i >= 0; i--)
			heapDown(l, i, n, le, swp);

		for(ssize_t i = n - 1; i > 0; i--){
			swp(*l, *(l + i));
			heapDown(l, 0, i, le, swp);
		}
		return;
	}

	template<typename T>
	static inline void heapDown(T *&l, size_t pos, size_t n, bool (&le)(T&, T&), void(&swp)(T&, T&)){
		size_t mx, lson, rson;
		do{
			mx = pos;
			lson = (pos << 1) + 1;
			rson = (pos << 1) + 2;
			if(lson < n && le(*(l + mx), *(l + lson)))
				mx = lson;
			if(rson < n && le(*(l + mx), *(l + rson)))
				mx = rson;

			if(mx != pos){
				swp(*(l + mx), *(l + pos));
				pos = mx;
			}else{
				break;
			}
		}while(true);
	}
};