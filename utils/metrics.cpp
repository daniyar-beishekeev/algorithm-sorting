#include <cstdlib>
#include <ctime>
#include <utility>
#include <pthread.h>
#include <unistd.h>

#include "memoryUsage.cpp"

inline uint64_t getCpuCycles(){
	struct timespec ts;
	clock_gettime(CLOCK_THREAD_CPUTIME_ID, &ts);
	return static_cast<uint64_t>(ts.tv_sec) * 1000000000ull + ts.tv_nsec;
}

//Counters to track how many operations used

uint64_t NUM_COMPARISONS = 0;
uint64_t NUM_SWAPS = 0;
uint64_t PEAK_MEMORY = 0;

struct BigMemoryInt{
	int value;

	//Single byte data type
	//1 MB
	static constexpr size_t _SIZE = 1024 * 1024;
	char _TRASH[_SIZE];
};

bool cmp(BigMemoryInt &a, BigMemoryInt &b){
	NUM_COMPARISONS++;
	return a.value < b.value;
}

void custom_swap(BigMemoryInt &a, BigMemoryInt &b){
	NUM_SWAPS++;
	//Boost swapping, necessary only
	std::swap(a.value, b.value);
}


bool cmp(int &a, int &b){
	NUM_COMPARISONS++;
	return a < b;
}

void custom_swap(int &a, int &b){
	NUM_SWAPS++;
	std::swap(a, b);
}

#include <iostream>

void* memoryTracker(void* arg){
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, nullptr);
	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, nullptr);
	while(true){
		uint64_t curMemory = getCurrentRSS();
		//std::cout << "MemUsage: " << curMemory << '\n';
		if(curMemory > PEAK_MEMORY)
			PEAK_MEMORY = curMemory;
		//usleep(1);
	}
}