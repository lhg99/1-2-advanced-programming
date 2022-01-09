#include <stdio.h>

int i;

void insertionsort(int arr[], int n)
{
	int j, temp;
	for (i = 0; i < n; i++)
	{
		temp = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = temp;
	}
}

int main()
{
	int arr[] = { 12, 5, 20, 15, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	insertionsort(arr, n);

	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;

}