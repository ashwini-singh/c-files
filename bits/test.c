// test.c

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bit_ops.h"

int main() {

	printf("start testing\n"); 

	int from = -100, to = 100; 
	for (int i = from; i <= to; i++) {
		assert(0 - i == negate(i)); 
		assert(((i % 2) == 0) == is_even(i)); 
		assert(i * 2 == multiply_by_two(i)); 
		if (is_even(i)) {
			assert(i / 2 == divide_by_two(i)); 
		}
	}

	for (int i = from;i <= to; i++) {
		for (int j = from; j <= to; j++) {
			assert(i + j == add_i(i, j)); 
			assert(i - j == subtract(i, j)); 
			assert(i * j == multiply(i, j)); 
		}
	}

	printf("end testing\n"); 
	return 0; 
}
