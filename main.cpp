#include <bits/stdc++.h>

//#include "traditional/merge-sort.cpp"
//#include "traditional/heap-sort.cpp"
//#include "traditional/bubble-sort.cpp"
//#include "traditional/insertion-sort.cpp"
//#include "traditional/selection-sort.cpp"
//#include "traditional/quick-sort.cpp"
#include "traditional/dual-quick-sort.cpp"

#define SORTER dualQuickSort

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

int main() {
	assert(RAND_MAX == 0x7fffffff);
	srand(time(0));

	int n = gen(5, 20);
	n = 2;

	cout << n << endl;
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

	if(!is_sorted(arr, arr + n)){
		cout << "Fail, not sorted array\n";
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return 1;
	}

	return 0;
}