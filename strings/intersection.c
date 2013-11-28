/* Takes two arrays. Returns a new array that contains intersection
 * fo two arrays 
 */ 

#include <stdio.h>

int main() {

	int a[] = {1, 2, 3, 4, 5, 6, 7}; 
	int b[] = {3, 6, 1, 2, 4, 6, 8}; 
	int result[10];		// size = max(size of a, size of b); 

	int *a_ptr = a, 
		*b_ptr = b; 

	// Iterate through all items in a. 
	int index = 0; 
	while (*a_ptr) {
		
		// Iterate through all items in b. 
		for (b_ptr = b; *b_ptr; *b_ptr++) {
			int seen = 0; 

			if (*a_ptr == *b_ptr && !seen) {
				*b_ptr = NULL; 
				result[index++] = *a_ptr; 
				seen = 1; 
			}
			else {
				*b_ptr = NULL; 
			}

		}
		*a_ptr++; 
	}


	int i; 
	for (i = 0; i < index; i++) {
		printf("%d: %d\n", i, result[i]); 
	}

	return 0; 
}
