#include <stdio.h>

int count_ones(int num); 

int main() {

	int num = 11; 
	int count = count_ones(num); 
	printf("count: %d\n", count); 

	return 0; 
}

// Counts the number of 1s in the binary 
// representation of a number
int count_ones(int num) {

	int count = 0; 
	while (num != 0) {
		if ((num & 1) == 1) {
			count++; 
		}
		num = num >> 1; 
	}

	return count; 
}
