#include <cstdlib>

class combSort{
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

		bool sorted = false;
		size_t gap = n;
		float shrink = 1.3;

		while(!sorted){
			gap = floor((float)gap / shrink);
			if(gap <= 1){
				gap = 1;
				sorted = true;
			}else if(gap == 9 || gap == 10){
				gap = 11;
			}

			for(T *i = l, *j = l + gap; j < r; i++, j++){
				if(le(*j, *i)){
					swp(*j, *i);
					sorted = false;
				}
			}
		}

		return;
	}
};