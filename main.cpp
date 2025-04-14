//Set sorting timeout to 5 seconds
const long long int TIMEOUT = 5;
#include <bits/stdc++.h>

#include "traditional/merge-sort.cpp"
#include "traditional/heap-sort.cpp"
#include "traditional/bubble-sort.cpp"
#include "traditional/insertion-sort.cpp"
#include "traditional/selection-sort.cpp"
#include "traditional/quick-sort.cpp"
#include "traditional/dual-quick-sort.cpp"

#include "experimental/library-sort.cpp"
#include "experimental/tim-sort.cpp"
#include "experimental/cocktail-shaker-sort.cpp"
#include "experimental/comb-sort.cpp"
#include "experimental/tournament-sort.cpp"
#include "experimental/intro-sort.cpp"

#include "utils/metrics.cpp"
#include "utils/gen.cpp"

using namespace std;

int main(int argc, char* argv[]){
	if(argc == 5 && (string)argv[1] == "gen"){
//		./main gen N testType outputPath
		int n = stoi(argv[2]);
		assert(n >= 0 && "Too small array size");
		assert(n <= (int)1e8 && "Warning! Too large array size, 100M");

		vector<int> (*generatorFunction)(int);
		string func = argv[3];

		if(func == "genPermutation")generatorFunction = genPermutation;
		else if(func == "genPermutationSorted")generatorFunction = genPermutationSorted;
		else if(func == "genPermutationReversed")generatorFunction = genPermutationReversed;
		else if(func == "genIdentical")generatorFunction = genIdentical;
		else if(func == "genBalanced")generatorFunction = genBalanced;
		else if(func == "genAbsolute")generatorFunction = genAbsolute;
		else if(func == "genAbsoluteSmall")generatorFunction = genAbsoluteSmall;
		else throw invalid_argument("Couldn't parse generating algorithm: " + func);

		FILE* file = fopen(argv[4], "w");
		if(file != NULL){
			vector<int> vec = generatorFunction(n);
			fprintf(file, "%d\n", n);
			for(int i = 0; i < n; i++){
				if(i > 0)
					fprintf(file, " ");
				fprintf(file, "%d", vec[i]);
			}
			fprintf(file, "\n");
			fclose(file);
		}else{
			throw invalid_argument("Can't open file: " + (string)argv[4]);
		}
	}else if(argc == 4 && (string)argv[1] == "test"){
//		./main test inputPath algorthim

		string algo = argv[3];
		void (*sortPtr)(int*, int*, bool (&)(int&, int&), void (&)(int&, int&));

		if(algo == "mergeSort")sortPtr = mergeSort::sort;
		else if(algo == "heapSort")sortPtr = heapSort::sort;
		else if(algo == "bubbleSort")sortPtr = bubbleSort::sort;
		else if(algo == "insertionSort")sortPtr = insertionSort::sort;
		else if(algo == "selectionSort")sortPtr = selectionSort::sort;
		else if(algo == "quickSort")sortPtr = quickSort::sort;
		else if(algo == "dualQuickSort")sortPtr = dualQuickSort::sort;
		else if(algo == "librarySort")sortPtr = librarySort::sort;
		else if(algo == "timSort")sortPtr = timSort::sort;
		else if(algo == "cocktailShakerSort")sortPtr = cocktailShakerSort::sort;
		else if(algo == "combSort")sortPtr = combSort::sort;
		else if(algo == "tournamentSort")sortPtr = tournamentSort::sort;
		else if(algo == "introSort")sortPtr = introSort::sort;
		else throw invalid_argument("Couldn't parse sorting algorithm: " + algo);

		FILE* file = fopen(argv[2], "r");
		if(file != NULL){
			int n;
			fscanf(file, "%d", &n);

			vector<int> vec(n);

			for(int i = 0; i < n; i++)
				fscanf(file, "%d", &vec[i]);
			int *arr = vec.data();
			fclose(file);

			//Keep original to track changed values. Dev only!
			vector<int> original = vec;

			//Start test
			//Start memory tracker
			//pthread_t thread;
			//assert(pthread_create(&thread, nullptr, memoryTracker, nullptr) == 0 && "Couldn't create memory tracker");
			//usleep(1000);

			auto initialMemory = getPeakRSS();
			auto initialTime = getCpuCycles();
			sortPtr(arr, arr + n, cmp, custom_swap);
			initialMemory = getPeakRSS() - initialMemory;
			initialTime = (getCpuCycles() - initialTime);

			//Stop memory tracker
			//usleep(1000);
			//pthread_cancel(thread);
			//pthread_join(thread, nullptr);

			//Freeze metrics

			assert(is_sorted(vec.begin(), vec.end()) && "Sorting algorithm is not sorted");

			sort(original.begin(), original.end());
			assert(original == vec && "Sorting algorithm modified array elements");

			int a = 2;
			int b = 3;
			custom_swap(a, b);
			cout << "Memory usage: " << initialMemory << '\n';
			cout << "CPU consume : " << initialTime << '\n';
			cout << "Swaps count : " << NUM_SWAPS << '\n';
			cout << "Comparions  : " << NUM_COMPARISONS << '\n';
			cout << "Success test\n";
		}else{
			throw invalid_argument("Can't open file: " + (string)argv[4]);
		}
	}else{
		cout << "Invalid command. Read the docs.\n";
	}
}