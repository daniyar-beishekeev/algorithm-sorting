//Set sorting timeout to 5 seconds
const long long int TIMEOUT = 5;

//Turn on randomizer for quicksort
#define RANDOMIZER 1

#include <bits/stdc++.h>
#include <sys/wait.h>

#include "utils/metrics.cpp"
#include "utils/gen.cpp"

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

using namespace std;

const pair<string, void (*)(int*, int*, bool (&)(int&, int&), void (&)(int&, int&))> SORTERS[] = {
	{"mergeSort", mergeSort::sort},
	{"heapSort", heapSort::sort},
	{"bubbleSort", bubbleSort::sort},
	{"insertionSort", insertionSort::sort},
	{"selectionSort", selectionSort::sort},
	{"quickSort", quickSort::sort},
	{"dualQuickSort", dualQuickSort::sort},
	{"librarySort", librarySort::sort},
	{"timSort", timSort::sort},
	{"cocktailShakerSort", cocktailShakerSort::sort},
	{"combSort", combSort::sort},
	{"tournamentSort", tournamentSort::sort},
	{"introSort", introSort::sort}
};


#define vi std::vector<int>

void testSorting(vi &toSort, vi &answer, void (*sortPtr)(int*, int*, bool (&)(int&, int&), void (&)(int&, int&)), string algoName, string comment){
	pid_t pid;
	pid = fork();
	//Sandbox sorting algorithm
	if(pid < 0){
		assert(pid >= 0 && "Failed to fork");
	}else if(pid == 0){//Child
		int n = toSort.size();
		int *arr = toSort.data();
//		cout << "Should be same (cur, peak): " << getCurrentRSS() << ' ' << getPeakRSS() << '\n';

		auto initialMemory = getPeakRSS();
		auto initialTime = getCpuCycles();

		sortPtr(arr, arr + n, cmp, custom_swap);

		initialTime = getCpuCycles() - initialTime;
		initialMemory = getPeakRSS() - initialMemory;

		assert(toSort == answer && "Wrong answer, array is not sorted");

		cout << "Comment     : " << comment << '\n';
		cout << "Result      : " << "Success" << '\n';
		cout << "Algorithm   : " << algoName << '\n';
		cout << "Memory usage: " << initialMemory << '\n';
		cout << "CPU consume : " << (double)initialTime * 1e-6 << '\n';
		cout << "Swaps count : " << NUM_SWAPS << '\n';
		cout << "Comparions  : " << NUM_COMPARISONS << '\n';
		cout << '\n';
		exit(0);
	}else{//Parent
		int status;
		pid_t result = waitpid(pid, &status, WNOHANG);
		for (int i = 0; i < TIMEOUT && result == 0; i++){
			sleep(1);
			result = waitpid(pid, &status, WNOHANG);
		}

		if (result == 0) {
			cout << "Comment     : " << comment << '\n';
			cout << "Result      : " << "Timeout" << '\n';
			cout << "Algorithm   : " << algoName << '\n';
			cout << "Memory usage: " << 0 << '\n';
			cout << "CPU consume : " << 0 << '\n';
			cout << "Swaps count : " << 0 << '\n';
			cout << "Comparions  : " << 0 << '\n';
			cout << '\n';
			kill(pid, SIGKILL);
			waitpid(pid, &status, 0);
		}
	}
}

int main(int argc, char* argv[]){
	if(argc == 5 && (string)argv[1] == "gen"){
//		./main gen N testType outputPath
		int n = stoi(argv[2]);
		assert(n >= 1 && "Too small array size");
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
//		./main test inputPath comment

		FILE* file = fopen(argv[2], "r");
		if(file != NULL){
			int n;
			fscanf(file, "%d", &n);

			vector<int> vec(n);

			for(int i = 0; i < n; i++)
				fscanf(file, "%d", &vec[i]);
			fclose(file);

			auto ans = vec;
			sort(ans.begin(), ans.end());

			string comment = argv[3];

			int sorts = sizeof(SORTERS) / sizeof(SORTERS[0]);
			for(int i = 0; i < sorts; i++){
				//Not necessary, CHeck required to remove
				vi vec2 = vec;
				testSorting(vec2, ans, SORTERS[i].second, SORTERS[i].first, comment);
			}

		}else{
			throw invalid_argument("Can't open file: " + (string)argv[4]);
		}
	}else{
		cout << "Invalid command. Read the docs.\n";
	}
}