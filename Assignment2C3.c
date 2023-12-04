#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 5


//function for recursive binary search
int bSRecur(int arr[], int left, int right, int search)
{
	if(left <= right)
	{
		int mid = left +(right - left)/2;

		if(arr[mid] == search)
		{
			return mid;
		}
			else if(arr[mid] < search)
			{
				return bSRecur(arr, mid + 1, right, search);
			}
				else
				{
					return bSRecur(arr, left, mid - 1, search);
				}

	}

	return -1;
}


int main()
{
	int arr[MAX_SIZE];
	int size, search;

	printf("First Last, abc123\nBinary Search (Recursive approach)\n");
		printf("Enter %d elements:\n", MAX_SIZE);

		for(int i = 0; i < MAX_SIZE; ++i)
		{
			printf("Enter element %d: ", i + 1);
			scanf("%d", &arr[i]);
		}

		size = MAX_SIZE;

		printf("Enter the element you wish to search: ");
		scanf("%d", &search);

		//records the time cpu cycle
		clock_t start = clock();
		int index = bSRecur(arr, 0, size - 1, search);
		clock_t stop = clock();

		if(index != -1)
		{
			printf("Element found at index: %d\n", index);
		}
			else
			{
				printf("Element not found in the array.\n");
			}

		double cpuCycles =((double)(stop - start))/CLOCKS_PER_SEC;
		printf("Total time take by CPU: %f seconds\n", cpuCycles);


		return 0;

	}
