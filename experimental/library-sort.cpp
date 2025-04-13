#include <cstdlib>

class librarySort{
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
	#define GAP_STRUCT(T) std::pair<bool, T>
	//bool = true  -> NOT GAP / USED
	//bool = false -> GAP / NOT USED

	template<typename T>
	static inline void rebalance(GAP_STRUCT(T) *S, uint &begin, uint &end, void(&swp)(T&, T&)){
		uint r = end;
		uint w = end * 2;

		while(r >= begin){
			swp(S[w].second, S[r].second);
			std::swap(S[w].first, S[r].first);
			assert(S[w - 1].first == false);

			r--;
			w -= 2;
		}
	}

	template<typename T>
	static inline size_t binarySearch(T &elem, GAP_STRUCT(T) *S, size_t k, bool (&le)(T&, T&)){
		for(size_t i = 1; i <= k; i++){
			if(S[i].first && le(elem, S[i].second))
				return i;
		}
		return k + 1;
	}

	template<typename T>
	static inline void insertRight(GAP_STRUCT(T) *S, size_t idx, T &elem, void(&swp)(T&, T&)){
		bool me = true;
		do{
			std::swap(me, S[idx].first);
			swp(elem, S[idx].second);
			idx++;
		}while(me);
	}

	template<typename T>
	static inline void insertLeft(GAP_STRUCT(T) *S, size_t idx, T &elem, void(&swp)(T&, T&)){
		bool me = true;
		do{
			std::swap(me, S[idx].first);
			swp(elem, S[idx].second);
			idx--;
		}while(me);
	}

	template<typename T>
	static inline void insert(GAP_STRUCT(T) *S, size_t &idx, T &elem, ssize_t k, void(&swp)(T&, T&)){
		for(ssize_t l = idx - 1, r = idx;; l--, r++){
			if(r <= k && !S[r].first)
				return insertRight(S, idx, elem, swp);
			if(l > 0 && !S[l].first)
				return insertLeft(S, idx - 1, elem, swp);
		}
	}

	template<typename T>
	//le -> less than comparator
	static inline void sort_runner(T *&l, T *&r, bool (&le)(T&, T&), void(&swp)(T&, T&)){
		size_t n = r - l;

		GAP_STRUCT(T) *S = new GAP_STRUCT(T)[n * 2 + 1];
		//I WILL USE 1 INDEXED ARRAY
		for(size_t i = 0; i <= n * 2; i++)
			S[i].first = false;


		S[1].first = true;
		swp(S[1].second, *l);


		uint level = std::floor(std::log2(n - 1)) + 1;
		for(uint i = 1; i <= level; i++){
			uint begin = 1;
			uint end = 1 << (i - 1);

			rebalance(S, begin, end, swp);

			size_t limit = std::min((size_t)1 << i, n);
			for(size_t j = (1 << (i - 1)) + 1; j <= limit; j++){
				T &toInsert = l[j - 1];
				size_t idx = binarySearch(toInsert, S, 1 << i, le);
				insert(S, idx, toInsert, 1 << i, swp);
			}
		}

		T *pivot = l;
		for(size_t i = 1; i <= n * 2; i++)
			if(S[i].first){
				assert(pivot < r);
				swp(*pivot, S[i].second);
				pivot++;
			}
		assert(pivot == r);

		delete[] S;
	}
};