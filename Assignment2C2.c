#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 5

//Function for iterative binary search
int bSIter(int arr[], int size, int search)
{
	int left = 0;
	int right = size - 1;

	while(left <= right)
	{
		int mid = left + (right - left)/2;

		if(arr[mid] == search)//checking position of x
		{
			return mid;
		}
			else if(arr[mid] < search)
			{
				left = mid + 1;
			}
				else
				{
					right = mid - 1;
				}

	}

	return -1;
}



int main()
{
	int arr[MAX_SIZE];
	int search;


	printf("First Last, abc123\nBinary Search (Iterative approach)\n");
	printf("Enter %d elements:\n", MAX_SIZE);

	for(int i = 0; i < MAX_SIZE; ++i)
	{
		printf("Enter element %d: ", i + 1);
		scanf("%d", &arr[i]);
	}

	printf("Enter the element you wish to search: ");
	scanf("%d", &search);

	//records time for cpu cycle
	clock_t start = clock();
	int index = bSIter(arr, MAX_SIZE, search);
	clock_t stop = clock();

	if(index != -1)
	{
		printf("Element found at index: %d\n", index);
	}
		else
		{
			printf("Element not found in the array.\n");
		}

	double cpuCycles =((double)(stop - start)) /CLOCKS_PER_SEC;
	printf("Total time take by CPU: %f seconds\n", cpuCycles);

	free(arr);


	return 0;
}

