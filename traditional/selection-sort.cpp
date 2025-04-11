#include <cstdlib>

class selectionSort{
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

		for(size_t i = 0; i < n; i++){
			size_t mn = i;
			for(size_t j = i + 1; j < n; j++)
				if(le(*(l + j), *(l + mn)))
					mn = j;

			if(mn != i)
				swp(*(l + i), *(l + mn));
		}
	}
};