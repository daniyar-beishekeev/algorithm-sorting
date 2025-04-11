#include <bits/stdc++.h>

//#include "traditional/merge-sort.cpp"
#include "traditional/heap-sort.cpp"

#define SORTER heapSort

using namespace std;

int gen(int l, int r) {
	return rand() % (r - l + 1) + l;
}

//Counters to track how many operations used

int NUM_COMPARISONS = 0;

bool cmp(int &a, int &b){
	NUM_COMPARISONS++;
	return a < b;
}

int main() {
	assert(RAND_MAX == 0x7fffffff);
	srand(time(0));

	int n = gen(5, 20);

	cout << n << endl;
	vector<int>vec(n);
	int *arr = (int*)vec.data();
	iota(arr, arr + n, 1);
	random_shuffle(arr, arr + n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << '\n';

	SORTER::sort(arr, arr + n, cmp);
	cout << NUM_COMPARISONS << '\n' << '\n';

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