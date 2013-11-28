/* Implement bubble sort */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

void bubble_sort(int* array, int size); 
void bubble_sort2(int* array, int size); 

void quicksort(int* array, int a, int b);
void quick_sort2 (int *a, int n); 

// void merge_sort(int *array, int low, int high); 
void Merge(int *a, int L, int mid, int R); 
void MergeSort(int *a, int L, int R); 

void insertion_sort(int *a, int size); 
void selection_sort(int *a, int size); 

int binary_search(int* a, int key, int min, int max); 

int main (int argc, char *argv[]) {

	int array[100]; 
	int size = sizeof(array)/sizeof(int);		// Fucks up sometimes with ptrs!

	// Set the seed for random numbers
	srand(time(NULL)); 

	// Insert random numbers into array
	// rand() returns psuedo-random integer between 0 and RAND_MAX
	// printf("array values: "); 
	for (int i = 0; i < size; i++) {
 		array[i] = rand() % 100; 	// between 0-99
		// iprintf("%d ", array[i]); 
 	}
	// printf("\n"); 

	if (!strcmp(argv[1], "-b_sort")) {
		bubble_sort(array, size); 
	}
	else if (!strcmp(argv[1], "-b_sort2")) {
		bubble_sort2(array, size); 
	}
	else if (!strcmp(argv[1], "-q")) {
		quicksort(array, 0, size - 1); 
	}
	else if (!strcmp(argv[1], "-q2")) {
		//quicksort2(array, size); 
		quick_sort2(array, size); 
	}
	else if (!strcmp(argv[1], "-merge")) {
		MergeSort(array, 0, size-1); 
	}
	else if (!strcmp(argv[1], "-insertion")) {
		insertion_sort(array, size); 
	}
	else if (!strcmp(argv[1], "-selection")) {
		selection_sort(array, size); 
	}
	else {
		printf("input sort to use\n"); 
	}

	// Print out array
	printf("sorted values: "); 
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]); 
	}
	printf("\n"); 

	int temp = binary_search(array, 10, 0, size-1); 
	if (temp != -1) {
		printf("index: %d\n", temp); 
	}

	return 0; 
}

/* General Bubble Sort
 *	
 *	Takes an array of unsorted integers and sorts
 *	in ascending order (lowest to highest). 
 *
 *  Stable
 *	Worst case: O(n^2) comparisons/swaps
 *
 */
void bubble_sort(int* array, int size) {

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {

			// Lowest to highest
			if (array[j] > array[j+1]) {
				int temp = array[j+1]; 
				array[j+1] = array[j]; 
				array[j] = temp; 
			}
		}
	}
}

/* Modified Bubble Sort
 *	
 *	Takes an array of unsorted integers and sorts
 *	in ascending order (lowest to highest). Uses
 *	a flag to check if any swaps were performed. 
 *	If not, that means array is already sorted
 *
 *  Stable
 *	Worst case: O(n^2) comparisons/swaps
 *
 */
void bubble_sort2(int* array, int size) {

	for (int i = 0; i < size; i++) {
		bool swap = false; 
		for (int j = 0; j < size - 1; j++) {

			// Lowest to highest
			if (array[j] > array[j+1]) {
				int temp = array[j+1]; 
				array[j+1] = array[j]; 
				array[j] = temp; 
				swap = true; 
			}
		}
		if (!swap) break; 
	}
}


/*  Quicksort (aka partition-exchange sort)
 *
 *  A divide and conquer algorithm where you choose a PIVOT
 *  and split the set into two subsets - values > pivot, and 
 *  values < pivot. Recursively applied until no more subsets 
 *  to split and the results are combined. 
 *
 *  Best pivot divides partitions into equal lengths. 
 *  Worst creates an empty partition (either extreme). 
 *
 *  NOTE: This specific implementation sorts IN PLACE. 
 *  No addition memory overhead from storage
 *
 *  Worst case: O(n log(n)) sorts
 */
 
void quicksort (int* array, int start, int end) {

	if (start >= end) return; 

	int pivot = array[start];	// Set pivot as first value in array

	int i = start + 1;		// SKIP PIVOT POSITION
	int j = end; 

	// Set half of array as > pivot, and other half < pivot. 
	while (i < j) {
		while (i < j && array[j] >= pivot) {
			--j; 
		}
		while (i < j && array[i] <= pivot) {
			++i; 
		}
		if (i < j) {
			int temp = array[j]; 
			array[j] = array[i]; 
			array[i] = temp; 
		}
	}

	if (array[start] > array[i]) {
		int temp = array[i]; 
		array[i] = array[start]; 
		array[start] = temp; 

		quicksort(array, start, i - 1); 
		quicksort(array, i + 1, end); 
	}
	else {
		quicksort(array, start + 1, end); 
	}
}

// Another implementation of quicksort
void quick_sort2 (int *array, int size) {
    if (size< 2) return;

    int pivot = array[size / 2];
    int *left = array;
    int *right = array + size - 1;
    while (left <= right) {
        if (*left < pivot) {
            left++;
            continue;
        }
        if (*right > pivot) {
            right--;
            continue; 
        }
        int temp = *left;
        *left++ = *right;
        *right-- = temp;
    }
    quick_sort2(array, right - array + 1);
    quick_sort2(left, array + size - left);
}

// Merge sort - DIVIDE AND CONQUER
// 1. Divide the unsorted list into n sublists each containing 1 
//	element. 
// 2. Conquer - repeatedly merge sublists to produce new sorted sublists. 
//
// Sort array between indexes. Initially call merge_sort(int[] a, 0, len(a)-1)
void MergeSort(int* a, int L, int R) {
  
    if (R <= L) return; 
    
    int mid = (R-L)/2 + L;
    // Sort left half.
    MergeSort(a, L, mid);
    // Sort right half.
    MergeSort(a, mid+1, R);
    // Merge.
    Merge(a, L, mid, R);
}

   
// This is the key step!  
// Test corner cases!
void Merge(int *a, int L, int mid, int R) {
    // Scratch space which holds the merged elements.
    // int [] tmp = new int[R-L+1];
	int tmp[R-L+1]; 
    
    int i = L;  // pointer to left half.
    int j = mid+1; // pointer to right half.
    int to_write = 0; // pointer to merge space.
    
    // Try to merge till we reach the end of the first part.
    while (i <= mid) {
        // either out of right half elements, or we need to copy
        // element from left half.
        if (j > R || a[i] <= a[j]) {
            tmp[to_write++] = a[i++];
        } else {
            tmp[to_write++] = a[j++];
        }
    }
    
    // There might be elements left over from the right part.
    while (j <= R) {
        tmp[to_write++] = a[j++];
    }
    
    // Now modify the original array to the sorted version.
    for (int k = 0 ; k < (R-L+1); k++) {
        a[L+k] = tmp[k];
    }
}

// Insertion Sort
//
// O(n^2) sorting algorithm. Moves elements one at a time into 
// correct position. 
//
// Low overhead, good choice if array is small OR as finishing
// off algorithm for merge/quick sort. 
//
// Works better when the array is mostly sorted...?
void insertion_sort(int *a, int size) {
	int temp, 
		i, j; 

	for (i = 1; i < size; i++) {
		temp = a[i]; 
		for (j = i; j > 0 && temp < a[j - 1]; j--) {
			a[j] = a[j - 1]; 
		}
		a[j] = temp; 
	}
}

// Selection sort
// 
// Finds the smallest elmement in the array and exchanges it with
// the element in the first position, then second smallest...
//
// O(n^2). Good for when writing data is very slow compared to reading
// Least data movement of all the sorting 
void selection_sort(int *a, int size) {
	int i, j, 
		min, temp; 

	for (i = 0; i < size; i++) {
		min = i; 
		for (j = i; j < size; j++) {
			if (a[j] < a[min]) {
				min = j; 
			}
		}
		temp = a[i]; 
		a[i] = a[min]; 
		a[min] = temp; 
	}
}

// Recursive implementation of binary search 
int binary_search(int* a, int key, int min, int max) {

	// BASE CASE: Empty array
	if (max <= min) {
		return -1; 
	}
	else {

		int mid = (max - min)/2 + min; 

		if (key < a[mid]) {
			return binary_search(a, key, min, mid-1); 
		}
		else if (key > a[mid]) {
			return binary_search(a, key, mid+1, max); 
		}
		else {
			return mid; 
		}
	}
}
