#include <cstdlib>

class bubbleSort{
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

		bool swapped;
		do{
			swapped = false;
			for(size_t i = 1; i < n; i++)
				if(le(*(l + i), *(l + i - 1))){
					swp(*(l + i), *(l + i - 1));
					swapped = true;
				}
		}while(swapped);
		return;
	}
};