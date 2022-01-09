#include <stdio.h>
int main()
{
	int a = 1; //int형 변수 a를 1로 지정
	float b = 10.0; //float형 변수 b를 10.0으로 지정

	printf("%f\n", *(float *)&a); //int형 변수인 a의 데이터값을 float형으로 출력
	printf("%d\n", *(int *)&b); //float형 변수인 b의 데이터값을 int형으로 출력

	return 0;
}