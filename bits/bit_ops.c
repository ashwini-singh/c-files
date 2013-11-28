// bit_ops.c 

#include <stdio.h>

int add_r(int a, int b) {
	if (b == 0) return a; 
	int sum = a ^ b; 
	int carry = (a & b) << 1; 
	return add_r(sum, carry); 
}

int add_i(int a, int b) {

	while (b) {
		int carry = a & b; 
		a = a ^ b; 
		b = carry << 1; 
	}

	return a; 
}

int negate(int x) {
	return add_i(~x, 1); 
}

int subtract(int x, int y) {
	return add_i(x, negate(y)); 
}

int is_even(int n) {
	return !(n & 1); 
}

int divide_by_two(int n) {
	return n >> 1; 
}

int multiply_by_two(int n) {
	return n << 1; 
}

int multiply(int x, int y) {
	int result = 0; 

	if (x < 0 && y < 0) {
		return multiply(negate(x), negate(y)); 
	}

	if (x >= 0 && y < 0) {
		return multiply(y, x); 
	}

	while (y > 0) {
		if (is_even(y)) {
			x = multiply_by_two(x); 
			y = divide_by_two(y); 
		} 
		else {
			result = add_i(result, x); 
			y = add_i(y, -1); 
		}
	}

	return result; 
}


