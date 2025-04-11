#include <cstdlib>
#include <chrono>
#include <random>

//#define RANDOMIZER 1

class quickSort{
public:
	//Merge sort, instead of copying values, swaps each 

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
	static void sort_runner(T *l, T *r, bool (&le)(T&, T&), void(&swp)(T&, T&)){
		if(l + 1 < r){
			#ifdef RANDOMIZER
				static std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
				std::uniform_int_distribution<size_t> dist(0, r - l - 1);
				swp(*l, *(l + dist(gen)));
			#endif

			T *pivot = partition(l, r, le, swp);
			sort_runner(l, pivot, le, swp);
			sort_runner(pivot + 1, r, le, swp);
		}
		return;
	}

	template<typename T>
	static inline T* partition(T *&l, T *&r, bool (&le)(T&, T&), void(&swp)(T&, T&)){
		T *i = l;
		T *j = r;
		T *&pivot = l;
		while(true){
			do i++; while(le(*i, *pivot));
			do j--; while(le(*pivot, *j));
			if(i < j)swp(*i, *j);
			else break;
		}
		if(j != pivot)
			swp(*pivot, *j);
		return j;
	}
};