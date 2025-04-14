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
Comment     : CustomComment
Result      : Success
Algorithm   : mergeSort
Memory usage: 0
CPU consume : 0.2702
Swaps count : 19952
Comparions  : 8699

Comment     : CustomComment
Result      : Success
Algorithm   : heapSort
Memory usage: 0
CPU consume : 0.2067
Swaps count : 9075
Comparions  : 16844

Comment     : CustomComment
Result      : Success
Algorithm   : bubbleSort
Memory usage: 0
CPU consume : 4.4018
Swaps count : 250291
Comparions  : 954045

Comment     : CustomComment
Result      : Success
Algorithm   : insertionSort
Memory usage: 0
CPU consume : 2.7142
Swaps count : 250291
Comparions  : 251286

Comment     : CustomComment
Result      : Success
Algorithm   : selectionSort
Memory usage: 0
CPU consume : 1.2856
Swaps count : 995
Comparions  : 499500

Comment     : CustomComment
Result      : Success
Algorithm   : quickSort
Memory usage: 0
CPU consume : 0.1451
Swaps count : 2842
Comparions  : 11895

Comment     : CustomComment
Result      : Success
Algorithm   : dualQuickSort
Memory usage: 0
CPU consume : 0.2111
Swaps count : 6490
Comparions  : 11033

Comment     : CustomComment
Result      : Success
Algorithm   : librarySort
Memory usage: 0
CPU consume : 0.3416
Swaps count : 13506
Comparions  : 8580

Comment     : CustomComment
Result      : Success
Algorithm   : timSort
Memory usage: 0
CPU consume : 0.2582
Swaps count : 17511
Comparions  : 13324

Comment     : CustomComment
Result      : Success
Algorithm   : cocktailShakerSort
Memory usage: 0
CPU consume : 4.2189
Swaps count : 250291
Comparions  : 520479

Comment     : CustomComment
Result      : Success
Algorithm   : combSort
Memory usage: 0
CPU consume : 0.1809
Swaps count : 4309
Comparions  : 21704

Comment     : CustomComment
Result      : Success
Algorithm   : tournamentSort
Memory usage: 0
CPU consume : 0.4572
Swaps count : 2000
Comparions  : 8672

Comment     : CustomComment
Result      : Success
Algorithm   : introSort
Memory usage: 0
CPU consume : 0.1221
Swaps count : 3593
Comparions  : 12263
```