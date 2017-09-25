#include <stdio.h>
#include <malloc.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int partition(int *arr, int start, int end)
{
	int pivot = arr[end];
	int partitionindex = start;
	int i;
	for(i = start; i< end; i++)
	{
		if(arr[i] <= pivot)
		{
			swap(&arr[i], &arr[partitionindex]);
			partitionindex++;
		}
	}
	swap(&arr[partitionindex], &arr[end]);
	return partitionindex;
}

void quick_sort(int *arr, int start, int end)
{
	if(start < end) {
		int partitionindex = partition(arr, start, end);
		quick_sort(arr, start, partitionindex-1);
		quick_sort(arr, partitionindex+1, end);
	}
}

int main()
{
	int *arr;
	int n, i;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	arr = (int *)malloc(sizeof(int)*n);
	for(i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}

	quick_sort(arr,0,n-1);

	printf("sorted elements are:\n"); 
	for(i = 0; i < n ; i++)
	{
		printf("%d\n",arr[i]);
	}	

}