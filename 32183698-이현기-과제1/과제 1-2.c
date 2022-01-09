#include <stdio.h>
#include <time.h>

int main()
{
	int set[1000][1000] = {0, }; 
	int start = (int)time(NULL); 

	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
			printf("%d \n", set[i][j]);
	}

	printf("걸린 시간: %d \n", (int)time(NULL) - start);

	return 0;
}
