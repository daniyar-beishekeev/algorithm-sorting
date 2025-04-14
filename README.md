# Sorting Algorithm Tester 🚀

A utility program for generating test data and benchmarking different sorting algorithms.

Supports multiple input patterns and allows benchmarking various sorting methods for performance and correctness.

## Implemented sorting algorithms

-     Traditional basic (code used in CLI)
- ✅ Merge Sort (mergeSort)
- ✅ Heap Sort (heapSort)
- ✅ Bubble Sort (bubbleSort)
- ✅ Insertion Sort (insertionSort)
- ✅ Selection Sort (selectionSort)
- ✅ Quick Sort with/without RANDOMIZER (quickSort)
- ✅ Dual Pivot Quick Sort with/without RANDOMIZER (dualQuickSort)
-     Modern sorting algorithms
- ✅ Library Sort (librarySort) 
- ✅ Tim Sort (timSort)
- ✅ Cocktail-Shaker Sort (cocktailShakerSort)
- ✅ Comb Sort (combSort)
- ✅ Tournament Sort (tournamentSort)
- ✅ Intro Sort (introSort)
--- ./main test <INPUT FILE> (COMMENT OPTIONAL) (SORTING ALGORITHM OPTIONAL)
--- Sample usage ./main test input.txt "Testing input.txt" heapSort,timSort
--- WARNING!!! Program is very case sensitive

## Generators available
- For all generators N value should be given

### `genPermutation`
- Random permutation from 1 to N

### `genPermutationSorted`
- Sorted permutation from 1 to N

### `genPermutationReversed`
- Reversily sorted permutation from N to 1

### `genIdentical`
- Same number(1)

### `genBalanced`
- Equal number of random numbers from 1 to \sqrt{N}

### `genAbsolute`
- Random numbers from 1 to N

### `genAbsoluteSmall`
- Random numbers from 1 to \sqrt{N}

--- ./main gen <N> testType outputPath
--- Sample usage ./main gen genPermutation sampleTest.in
--- WARNING!!! Program is very case sensitive

## Build

Make sure you have a C++ compiler and Python interpretor installed.
Build and tested on Linux Ubuntu 22.04.5 LTS (jammy)
To build the project:

```bash
make all
```
Add or remove -DRANDOMIZER in Makefile to enable/disable randomizer for Quick Sorts

## P.S.
```
Comment     : CustomComment
Result      : Success/Timeout (Defined in main.cpp, default is 5 seconds)
Algorithm   : Sorting algorithm
Memory usage: -> in Bytes (B)
CPU consume : -> in Milliseconds (ms)
Swaps count : -> Number of swaps
Comparions  : -> Number of comparisons used

Shell scripts:

Generate tests
./genTests.sh

Define number of tests should be generated in genTests.sh
Ex: arr_n=(10 100)
types=(
  "3 genPermutation"
  "2 genAbsoluteSmall"
  etc

--> For n = 10/100 generate 3 tests using genPermutation, 2 tests using genAbsoluteSmall, etc...


Run tests
./runTests.sh
(RUNS EACH ALGORITHM EVEN TIMEOUT FOR BIG TESTS USE BELOW INSTEAD)
python3 smartRunner.py

smartRunner.py, will skip big tests if algorithm fails in a small

Use python3 txt2csvReport.py
To convert report.txt file to report.csv (Good for analysis)
```

## Example

```bash
./main test input.txt CustomComment
```

```
Comment     : Comment
Result      : Success
Algorithm   : mergeSort
Memory usage: 4288512
CPU consume : 328.885
Swaps count : 39902848
Comparions  : 9884992

Comment     : Comment
Result      : Success
Algorithm   : heapSort
Memory usage: 176128
CPU consume : 317.317
Swaps count : 19787792
Comparions  : 37692069

Comment     : Comment
Result      : Success
Algorithm   : bubbleSort
Memory usage: 0
CPU consume : 4.1476
Swaps count : 0
Comparions  : 999999

Comment     : Comment
Result      : Success
Algorithm   : insertionSort
Memory usage: 0
CPU consume : 6.8448
Swaps count : 0
Comparions  : 999999

Comment     : Comment
Result      : Timeout
Algorithm   : selectionSort
Memory usage: 0
CPU consume : 0
Swaps count : 0
Comparions  : 0

Comment     : Comment
Result      : Success
Algorithm   : quickSort
Memory usage: 339968
CPU consume : 97.628
Swaps count : 1166798
Comparions  : 25843723

Comment     : Comment
Result      : Success
Algorithm   : dualQuickSort
Memory usage: 344064
CPU consume : 165.001
Swaps count : 10656534
Comparions  : 24169075

Comment     : Comment
Result      : Timeout
Algorithm   : librarySort
Memory usage: 0
CPU consume : 0
Swaps count : 0
Comparions  : 0

Comment     : Comment
Result      : Success
Algorithm   : timSort
Memory usage: 4284416
CPU consume : 241.643
Swaps count : 30000000
Comparions  : 8457856

Comment     : Comment
Result      : Success
Algorithm   : cocktailShakerSort
Memory usage: 0
CPU consume : 3.0246
Swaps count : 0
Comparions  : 999999

Comment     : Comment
Result      : Success
Algorithm   : combSort
Memory usage: 0
CPU consume : 108.018
Swaps count : 0
Comparions  : 45666766

Comment     : Comment
Result      : Success
Algorithm   : tournamentSort
Memory usage: 68345856
CPU consume : 353.601
Swaps count : 2000000
Comparions  : 10066432

Comment     : Comment
Result      : Success
Algorithm   : introSort
Memory usage: 356352
CPU consume : 381.146
Swaps count : 19788834
Comparions  : 75690210
```
