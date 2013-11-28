#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse (char *s) {

	int i = 0, 
		len = strlen(s), 
		j = len - 1; 

	while (i < j) {
		int temp = s[i]; 
		s[i++] = s[j]; 
		s[j--] = temp; 
	}
}

void reverse2(char *begin, char *end) {
	char temp; 
	while (begin < end) {
		temp = *begin; 
		*begin++ = *end; 
		*end-- = temp; 
	}
}

// Reverse the ordering of words in a string 
void reverse_words(char* s) {

	reverse2(s, s + strlen(s) - 1); 

	char *begin = s; 
	char *temp = s; 

	while (*temp) {
		temp++; 
		if (*temp == '\0') {
			reverse2(begin, temp-1); 
		}
		else if (*temp == ' ') {
			reverse2(begin, temp-1); 
			begin = temp+1; 
		}
	}
}

// Function that reverses a number 
int reverse_num(int x) {

	int r = 0, 
		d = 10, 
		s = 0; 

	while (x > 0) {
		int remainder = x % 10; 
		r = (r * 10) + remainder; 
		s = 0; 

		// Sets x to one factor of 10 lower 
		while (x > 10) {
			x -= d; 
			s++; 
		}
		x = s; 
	}
	return r; 
}

// Function that converts a str to an integer: 
// ALG: 
//	Go through the string. 
//	Multiply current number by 10 every interation. 
//	Add the difference between a character and the 
//		character '0'. 
//	Apply negative if there is one. 
int str2int(char *str) {
	
	int num = 0; 
	int neg = 0; 

	// Check if negative 
	if (str[0] == '-') {
		neg = 1; 
		str++; 
	}

	// Go through the string 
	for (; *str; str++) {
		num *= 10;				// KEY STEP. Add the difference between
		num += (str[0] - '0');	// the character and 0 to get its value. 
	}

	if (neg) {
		num *= -1; 
	}

	return num; 
}

// Function that converts an integer to a string
char *int2str(int x) {

	// If negative, set as positive and set flag 
	int neg = 0; 
	if (x < 0) {
		x *= -1; neg = 1; 
	}

	char *temp = malloc(sizeof(char) * 100); 
	char *string = malloc(sizeof(char) * 100); 

	int i = 0, 
		index = 0; 

	// Go through the number. Add the converted units
	// digit to the temp buffer and divide to lower by a factor of 10. 
	while (x != 0) {
		temp[i++] = (char)((x % 10) + '0');		// (char) optional
		x /= 10; 
	}

	// Build the string in correct order 
	if (neg) {
		string[index++] = '-'; 
	}

	// Go through and set string as reverse of temp buffer 
	while (i > 0) {
		string[index++] = temp[--i]; 
	}
	string[index] = '\0';		// MANUALLY SET NULL TERMINATOR
	return string; 
}
