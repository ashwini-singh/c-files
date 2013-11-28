/* Check the endian-ness of your computer using C 
 *
 * Ex. 90AB12CD (32 bits)
 *
 * Little-endian (Lowest bit, lowest address): 
 *	- Kind of how you would read it too. 
 *		Address		Value
 *		1000		CD
 *		1001		12
 *		1002		AB	
 *		1003		90
 *
 * Big-endian: 
 *		Address		Value
 *		1000		90
 *		1001		AB
 *		1002		12
 *		1003		CD
 *
 *	PROS: By having first byte first, you can always test the sign
 *	
 *
 *
 */

#include <stdio.h>
#include <stdint.h>

void check_endian(); 
void check_endian2(); 
uint16_t swap_uint16( uint16_t val); 

int main() {

	check_endian2(); 

	uint16_t val = 403; 
	swap_uint16(val); 


	return 0; 
}

// Byte swap if you are changing from a system with one representation
// to another. Takes an unsigned 16 bit short and returns the swapped value
uint16_t swap_uint16( uint16_t val) {

	return (val << 8) | (val >> 8);
}

// Gets the address of an integer, then treats the address
// as a character pointer and writes data into the bytes
// that comprise the integer. Then, read out what is actually 
// in the integer and see if you get a result consistent with
// big/little endian architecture.
void check_endian() {
	int num = 1; 
	if (*(char *)&num == 1) {
		printf("Little-endian\n"); 
	} 
	else {
		printf("Not little-endian\n"); 
	}
}

// Uses union. Lets you access the same data with different variable types
void check_endian2() {
	union {
		int theInteger; 
		char singleByte; 
	} check_endian; 

	check_endian.theInteger = 1; 
	if (check_endian.singleByte) {
		printf("Little-endian\n"); 
	} 
	else {
		printf("Big-endian\n"); 
	}
}

