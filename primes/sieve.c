/* Sieve of Eratosthenes 
 *
 * Given a number N print all primes from 0 to N inclusive
 *
 * ALG: 
 * 1. Create a list of all positive integers
 * 2. Start at first valid number and elimate all of its 
 *	multiples from the list. 
 * 3. Advance to next valid number. Continue until no more valid 
 *	numbers to advance to. 
 */ 

#include <stdio.h>
#include <stdlib.h>
// #define LIMIT 1500000	// Size of integer array
#define PRIMES 100000	// Size of primes array 

int main(int argc, char *argv[]) {

	int i, j; 
	if (argc == 1) {
		printf("Input a value for N\n"); 
		return 0; 
	}

	int n = atoi(argv[1]); 
	int numbers[n]; 
	int primes[PRIMES]; 

	// Fill array with numbers 
	for (i = 0; i < n; i++) {
		numbers[i] = i+2;		// i + 2 because 1 not really prime 
	}

	// Run seive on non primes
	for (i = 0; i < n; i++) {
		if (numbers[i] != -1) {
			for (j = 2 * numbers[i] - 2; j < n; j += numbers[i]) {
				numbers[j] = -1; 
			}
		}
	}

	// Transfer primes to own array
	j = 0; 
	for (i = 0; i < n && j < PRIMES; j++) {
		if (numbers[i] != -1) {
			primes[j++] = numbers[i]; 
		}
	}
	
	// Print them all out
	for (i = 0; i < PRIMES; i++) {
		printf("%d ", primes[i]); 
	}

	return 0; 
}

