#include <stdio.h>
#define _CRT_SECURE_NO_WARINGS

void quicksort(int arr[], int left, int right);


void quicksort(int arr[], int left, int right)
{
	int i = left, j = right;
	int pivot = arr[(left + right) / 2];
	int temp;

	while (i<=j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;

		if (i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}

	if (left < j)
		quicksort(arr, left, j);
	if (i < right)
		quicksort(arr, i, right);
}

int main()
{
	int q;
	int arr[] = { 50,20,60,40,25 };
	int n = sizeof(arr) / sizeof(arr[0]);

	quicksort(arr, 0, 4);

	for (q = 0; q < n; q++)
		printf("%d ", arr[q]);
	printf("\n");

	return 0;

}