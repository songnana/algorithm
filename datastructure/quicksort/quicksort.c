#include <stdio.h>

#define NUMB 10
void quicksort(int *base, int start, int end);
void print(int *data, int numb);

void swap(int *s, int *d)
{
	int t;

	t = *s;
	*s = *d;
	*d = t;
}

int partition(int *base, int start, int end)
{
	int i, j;
	int bench;
	
	i = start;
	j = end-1;

	bench = base[end];
	
	while(i < j)
	{
		while(base[i]<bench) i++;
		while(base[j]>bench) j--;
		if(i<j)
		{
			printf("i:%d,j:%d\n",i,j);
			swap(&base[i],&base[j]);
			print(base,NUMB);
		}
		else break;
	}
	printf("i >= j, i:%d,j:%d\n",i,j);
	swap(&base[i],&base[end]);
	print(base,NUMB);
	
	return i;
}
	
void quicksort(int *base, int start, int end)
{
	int mid;
	
	printf("start:%d,end:%d\n",start,end);
	print(base, NUMB);

	if(start >= end) return;

	if(start==(end-1))
	{
		if(base[start]>base[end])	swap(&base[start],&base[end]);
		return;
	}


	mid = partition(base,start,end);
		
	print(base, NUMB);
	printf("mid:%d\n",mid);
	quicksort(base,start,mid-1);
	quicksort(base,mid+1,end);

	return;

}

void print(int *data, int numb)
{
	int i = 0;

	for(i = 0; i < numb; i++)
	{
		printf("%d\t", data[i]);
	}
	printf("\n");
	return;
}


int main()
{
	int data[NUMB] = {5,20,7,2,11,6,3,15,30,10};
	//int data[NUMB] = {3,5};
	
	print(data,sizeof(data)/sizeof(data[0]));
	
	//partition(data,0,numb-1);
	quicksort(data,0,NUMB-1);
	
	print(data,sizeof(data)/sizeof(data[0]));
	
	return 0;
}
