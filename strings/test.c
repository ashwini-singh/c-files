#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strings.h"

int main(int argc, char* argv[]) {

	// int temp = str2int("-2424"); 
	// printf("%d\n", temp); 

	// char *temp = int2str(-10234920); 
	// printf("%s\n", temp); 

	char string[] = "this is a string";

	reverse(string); 
	printf("new string: %s\n", string); 

	return 0; 
}

