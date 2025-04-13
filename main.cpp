#include <bits/stdc++.h>

//#include "traditional/merge-sort.cpp"
//#include "traditional/heap-sort.cpp"
//#include "traditional/bubble-sort.cpp"
//#include "traditional/insertion-sort.cpp"
//#include "traditional/selection-sort.cpp"
//#include "traditional/quick-sort.cpp"
//#include "traditional/dual-quick-sort.cpp"

#include "experimental/library-sort.cpp"
//#include "experimental/tim-sort.cpp"
//#include "experimental/cocktail-shaker-sort.cpp"
//#include "experimental/comb-sort.cpp"
//#include "experimental/tournament-sort.cpp"
//#include "experimental/intro-sort.cpp"

#define SORTER librarySort

using namespace std;

int gen(int l, int r) {
	return rand() % (r - l + 1) + l;
}

//Counters to track how many operations used

int NUM_COMPARISONS = 0;
int NUM_SWAPS = 0;

bool cmp(int &a, int &b){
	NUM_COMPARISONS++;
	return a < b;
}

void custom_swap(int &a, int &b){
	NUM_SWAPS++;
	swap(a, b);
}

inline uint64_t getCpuCycles() {
	struct timespec ts;
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &ts);
    return static_cast<uint64_t>(ts.tv_sec) * 1000000000ull + ts.tv_nsec;
}

int main() {
	auto start = getCpuCycles();

	assert(RAND_MAX == 0x7fffffff);
	srand(time(0));

	int n = gen(5, 20);
	
	vector<int>vec(n);
	int *arr = (int*)vec.data();
	iota(arr, arr + n, 1);
	random_shuffle(arr, arr + n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << '\n';

	SORTER::sort(arr, arr + n, cmp, custom_swap);
	cout << "Comparisons: " << NUM_COMPARISONS << '\n';
	cout << "Swaps      : " << NUM_SWAPS << '\n';

	for(int i = 0; i < n; i++){
		assert(arr[i] == i + 1);
	}

	if(!is_sorted(arr, arr + n)){
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		cout << "Fail, not sorted array\n";
		return 1;
	}
	cout << 1e-6 * (getCpuCycles() - start) << '\n';
	return 0;
}