#include <cstdlib>
#include <chrono>
#include <random>

//#define RANDOMIZER 1

class dualQuickSort{
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
				swp(*(r - 1), *(l + dist(gen)));
			#endif

			std::pair<T*, T*> pivot = partition(l, r, le, swp);
			sort_runner(l, pivot.first, le, swp);
			sort_runner(pivot.first + 1, pivot.second, le, swp);
			sort_runner(pivot.second + 1, r, le, swp);
		}
		return;
	}

protected:
	template<typename T>
	static inline std::pair<T*, T*> partition(T *&l, T *&r, bool (&le)(T&, T&), void(&swp)(T&, T&)){
		if(le(*(r - 1), *(l)))swp(*l, *(r - 1));
		T *left_pivot = l + 1;
		T *right_pivot = r - 2;
		T *i = l + 1;
		while(i <= right_pivot){
			if(le(*i, *l)){
				swp(*i, *left_pivot);
				left_pivot++;
				i++;
			}else if(le(*(r - 1), *i)){
				swp(*i, *right_pivot);
				right_pivot--;
			}else i++;
		}
		--left_pivot;++right_pivot;
		if(l != left_pivot)
			swp(*l, *left_pivot);
		if((r - 1) != right_pivot)
			swp(*(r - 1), *right_pivot);
		return std::make_pair(left_pivot, right_pivot);
	}
};