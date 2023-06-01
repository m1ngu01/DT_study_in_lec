#include <stdio.h>
#define SWAP(x,y,t) ( (t) = (x), (x) = (y), (y) = (t) )

void printArray(int arr[], int n, const char *str)
{
	int i;
	printf( "%s = ", str );
	for( i = 0; i <  n; i++ )
	{
		printf( "%3d", arr[i] );
	}
	printf("\n");
}

void printStep(int arr[], int n, arr[i])
{
	int i;
	printf("Step %2dd = ", val);
	for(i = 0; i<n; i++) printf("%3d", arr[i]);
	printf("\n");
}


void selection_sort(int arr[], int n)
{
	int i, j, least, tmp;
	for(i = 0; i < n-1; i++)
	{
		least = i;
		for(j = i+1; j<n; j++)
			if(list[j]<list[least]) least = j;
		SWAP(list[i],list[least],tmp);
		printStep(list, n, i+1);
	}
}

void insertion_sort(int list[], int n)
{
	int i, j, key;
	for(i = 1; i < n; i++)
	{
		key = list[i];
		for(j = i-1; j>=0 && list[j] > key; j--)
			list[j+1] = list[j];
		list[j+1] = key;
		printStep(list, n, i);
	}
}

int main(void)
{
	int i;
	for( i = 0; i < 9; i++)
		dcopy[i] = list[i];
	
	/*Selection sort*/
	selection_sort(list, 9);
	printArray(list, 9, "Selection");
	
	/*Insertion sort*/
	Insertion_sort(list, 9);
	printArray(list, 9, "Insertion");
	
	/*Bubble sort*/
	Bubble_sort(list, 9);
	printArray(list, 9, "Bubble");
	
}


