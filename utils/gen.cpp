#include <chrono>
#include <random>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());

long long gen(long long l, long long r){
	std::uniform_int_distribution<long long> dist(l, r);
	return dist(generator);
}

#define vi std::vector<int>

vi genPermutation(int n){
	vi ans(n);
	iota(ans.begin(), ans.end(), 1);
	std::shuffle(ans.begin(), ans.end(), generator);
	return ans;
}

vi genPermutationSorted(int n){
	vi ans(n);
	iota(ans.begin(), ans.end(), 1);
	return ans;
}

vi genPermutationReversed(int n){
	vi ans(n);
	iota(ans.begin(), ans.end(), 1);
	reverse(ans.begin(), ans.end());
	return ans;
}

vi genIdentical(int n){
	vi ans(n, 1);
	return ans;
}

vi genBalanced(int n){
	vi ans(n);
	for(int i = 0; i < n; i++)
		ans[i] = std::sqrt(i + 1);
	std::shuffle(ans.begin(), ans.end(), generator);
	return ans;
}

vi genAbsolute(int n){
	vi ans(n);
	std::uniform_int_distribution<long long> dist(1, n);
	for(int i = 0; i < n; i++)
		ans[i] = dist(generator);
	return ans;
}

vi genAbsoluteSmall(int n){
	vi ans(n);
	std::uniform_int_distribution<long long> dist(1, std::sqrt(n));
	for(int i = 0; i < n; i++)
		ans[i] = dist(generator);
	return ans;
}