#include <stdio.h>
int main()
{
	int a = 1; //int�� ���� a�� 1�� ����
	float b = 10.0; //float�� ���� b�� 10.0���� ����

	printf("%f\n", *(float *)&a); //int�� ������ a�� �����Ͱ��� float������ ���
	printf("%d\n", *(int *)&b); //float�� ������ b�� �����Ͱ��� int������ ���

	return 0;
}