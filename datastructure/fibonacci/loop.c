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

/*
 * 逆向思维
 */

long long int fibonacci(int input)
{
	long long int f0 = 0;
	long long int f1 = 1;
	long long int f2;

	switch (input) {
	case 0:
		return f0;
	case 1:
		return f1;
	}

	while (input >= 2)
	{
		f2 = f0 + f1;
		f0 = f1;
		f1 = f2;
		input--;
	}

	return f1;
}


/*
 * for 正向思维
 */
/*
long long int fibonacci(int input)
{
	long long int f0 = 0;
	long long int f1 = 1;
	long long int f2;
	int i;

	switch (input) {
	case 0:
		return f0;
	case 1:
		return f1;
	}

	for (i = 2; i <= input; i++)
	{
		f2 = f0 + f1;
		f0 = f1;
		f1 = f2;
	}

	return f1;
}
*/
void usage()
{
	printf("Usage:\n");
	printf("\ta.out number\n");
	return;
}
