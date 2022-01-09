#include <stdio.h>
#include <string.h>
#define CRT_SECURE_NO_WARNINGS

struct information
{
	int student_number;
	char name[7];
	int mid_exam;
	int final_exam;
};
typedef struct information information;

int main()
{
	FILE *f;
	FILE *f1;

	char fname[] = "score.txt";
	char f_name[] = "grade.txt";
	int i, j, temp, temp1, temp2;
	int average[20], rank[20];
	char swap;
	char temp3[7];
	char grade[20][7];

	if (fopen_s(&f, fname, "w") != 0)
	{
		printf("파일이 열리지 않습니다.");
		exit(1);
	};

	information a[] = { { 32180023, "김기열", 50, 60 }, {32180037, "김단비", 25, 35}, {32180058, "김봉준", 35, 65}, {32180150, "김인직", 55, 65}, 
	{32180210, "김승우", 55, 95}, {32180230, "나상욱", 45, 35}, {32180300, "박광섭", 75, 85}, {32182927, "박수빈", 85, 95}, 
	{32182930, "박수홍", 60, 40}, {32182933, "박제욱", 80, 90}, {32183011, "박현제", 35, 55}, {32183022, "신호균", 60, 70}, 
	{32183302, "오준석", 80,60}, {32183330, "유인나", 30, 60}, {32183690, "이지은", 100, 100}, {32183698, "이현기", 70, 50 }, 
	{32183809, "정  민", 50, 50}, {32183902, "최원준", 30, 40}, {32184982, "하헌주", 40, 60}, {32184992, "하석현", 95, 85} };
	printf("학번      이름      중간    기말 \n");

	fprintf(f, "학번     이름      중간    기말 \n");

	for (i = 0; i < 20; i++)
	{
		printf("%8d %3s    %4d    %4d\n", a[i].student_number, a[i].name, a[i].mid_exam, a[i].final_exam);

		fprintf(f,"%8d %3s    %4d    %4d\n", a[i].student_number, a[i].name, a[i].mid_exam, a[i].final_exam);
	}
	fclose(f);

	if (fopen_s(&f, fname, "r") != 0)
	{
		printf("파일이 열리지 않습니다.");
		exit(1);
	};

	for (i = 0; i < 20; i++)
	{
		fscanf(f, "%d %s %d %d\n", &a[i].student_number, a[i].name, &a[i].mid_exam, &a[i].final_exam);

		average[i] = ( a[i].mid_exam + a[i].final_exam ) / 2;
		for (i = 0; i < 20; i++)
		{
			if (average[i] == average[i - 1])
				rank[i] = rank[i - 1];
			else
				rank[i] = i + 1;
		}

		swap = 'N';
		
		for (j = 0; j < j - i; j++)
		{
			if (average[j] < average[j + 1])
			{

				temp = a[j].student_number;
				a[j].student_number = a[j + 1].student_number;
				a[j + 1].student_number = temp;

				temp1 = a[j].mid_exam;
				a[j].mid_exam = a[j + 1].mid_exam;
				a[j + 1].mid_exam = temp1;

				temp2 = a[j].final_exam;
				a[j].final_exam = a[j + 1].final_exam;
				a[j + 1].final_exam = temp2;

				strcpy(temp3, a[j].name);
				strcpy(a[j].name, a[j + 1].name);
				strcpy(a[j + 1].name, temp3);

				swap = 'Y';
			}
		}
		if (swap == 'N')
			break;
	}

    if (fopen_s(&f1, f_name, "w") != 0)
	{
		printf("파일이 열리지 않습니다.");
		exit(1);
	};

	for (i = 0; i < 20; i++)
	{

		if (rank[i] <= (0.25*20))
			strcpy(grade[i], "A");
		else
			if (rank[i] <= (0.6*20))
				strcpy(grade[i], "B");
			else
				strcpy(grade[i], "C");

		swap = 'N';

		for (j = 0; j < j - i; j++)
		{
			if (a[j].student_number < a[j + 1].student_number)
			{
			
				temp1 = a[j].mid_exam;
				a[j].mid_exam = a[j + 1].mid_exam;
				a[j + 1].mid_exam = temp1;

				temp2 = a[j].final_exam;
				a[j].final_exam = a[j + 1].final_exam;
				a[j + 1].final_exam = temp2;

				strcpy(temp3, a[j].name);
				strcpy(a[j].name, a[j + 1].name);
				strcpy(a[j + 1].name, temp3);

				swap = 'Y';
			}
		}
		if (swap == 'N')
			break;
	}
		
	printf("학번      이름      중간    기말   등급\n");

	fprintf(f1, "학번     이름      중간    기말    등급\n");

	for (i = 0; i < 20; i++)
	{
		printf("%8d %3s    %4d    %4d    %s\n", a[i].student_number, a[i].name, a[i].mid_exam, a[i].final_exam, grade[i]);

		fprintf(f1, "%8d %3s    %4d    %4d   %s\n", a[i].student_number, a[i].name, a[i].mid_exam, a[i].final_exam, grade[i]);
	}
	fclose(f);
	fclose(f1);

	return 0;

}