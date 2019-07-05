#include <stdio.h>

long int fibonacci(int);

void usage();

int main(int argc, char **argv)
{
	int input;
	long int output;

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

	printf("the result of fibonacci %d is %ld\n", input, output);
	
	return 0;
}

long int fibonacci(int input)
{
	long int result;

	int f0 = 0;
	int f1 = 1;
	int f2;

	switch (input) {
	case 0:
		return f0;
	case 1:
		return f1;
	}

	while (input>=2)
	{
		f2 = f0 + f1;
		f0 = f1;
		f1 = f2;
		input--;
	}

	return f1;
}

void usage()
{
	printf("Usage:\n");
	printf("\ta.out number\n");
	return;
}
