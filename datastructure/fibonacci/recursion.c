#include <stdio.h>

long long int fibonacci(int);

void usage();

int main(int argc, char **argv)
{
	int input;
	long long int output;

	if (argc != 2) {
		usage();
		return 0;
	} 

	input = atoi(argv[1]);	

	if (input < 0) {
		printf("input must be >= 0");	
		usage();
		return 0;
	}

	output = fibonacci(input);

	printf("the result of fibonacci %d is %lld\n", input, output);
	
	return 0;
}

long long int fibonacci(int input)
{
	long long int result;

	if (input >= 2) {
		result = fibonacci(input-1) + fibonacci(input-2);
	} else {
		switch (input) {
		case 0:
			result = 0;
			break;
		case 1:
			result = 1;
			break;
		}
	}
	return result;
}

void usage()
{
	printf("Usage:\n");
	printf("\ta.out number\n");
	return;
}
