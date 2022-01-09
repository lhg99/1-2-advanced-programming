#include "homework.h"

struct NODE *findnode(NODE * node, char *name, int phone_num, char *address)
{
	if (node == NULL)
		return NULL;

	struct NODE *curr = node->next;
	while (curr != NULL)
	{
		if (curr->name == name)
			if (curr->phone_num=phone_num)
				if (curr->address=address)
					return curr;

		curr = curr->next;
	}

	return NULL;
}

int main()
{
	int a, d, g, Phone_num;
	char Name[7], Address[30];
	char *b="\0", *c="\0", *e="\0", *h="\0";
	char *fname = "contacts.txt";
	FILE *f;

	NODE *curr = malloc(sizeof(NODE));

	if (fopen_s(&f, fname, "w") != 0)
	{
		printf("파일이 열리지 않습니다.");
		exit(1);
	};
	fclose(f);

	printf("주소록 관리하는 프로그램입니다. 메뉴를 선택하십시요.\n");

	while (1)
	{
		printf("1. 삽입 2. 삭제 3. 검색 4. 출력 5. 종료");
		scanf("%d", &a);

		switch (a)
		{
		case 1: //삽입

			printf("이름, 전화번호, 이메일 주소를 입력해주세요.\n");
			 scanf("%s %d %s", Name, &Phone_num, Address);

			NODE *head = malloc(sizeof(NODE));
			add(head, Name, Phone_num, Address);
			break;

		case 2: //삭제

			printf("삭제할 이름, 전화번호, 이메일 주소를 입력하세요.\n");
			scanf("%s %d %s", c, &g, h);
			Removenode(head, c, g, h);

			struct NODE *curr = head->next;

			while (curr != NULL)
			{
				struct NODE *next = curr->next;
				free(curr);
				curr = next;
			}

			free(head);
			 
			break;

		case 3: //검색

			printf("검색할 이름 전화번호 이메일 주소를 입력하세요.\n");
			 scanf("%s %d %s", b, &d, e);

			 NODE *found = findnode(head, b,d,e);
				 printf("%s %d %s\n", found->name, found->phone_num, found->address);

	
			break;

		case 4: //출력

			printf("현재 등록된 주소록입니다.");
			
			while (curr != NULL)
			{
				printf("%s %d %s", curr->name, curr->phone_num, curr->address);
				curr = curr->next;
			}
			break;

		case 5: //종료 및 contacts.txt에 출력
			printf("프로그램을 종료합니다.");
			if (fopen_s(&f, fname, "w") != 0)
			{
				printf("파일이 열리지 않습니다.");
				exit(1);
			};

			for (curr = head->next; curr != NULL; curr = curr->next)
			{
				fprintf(f, "%s %d %s\n", curr->name, curr->phone_num, curr->address);
			}
			fclose(f);
			break;

		default: //잘못 선택했을시

			printf("잘못 선택하셨습니다.");
			break;
		}
	}

	return 0;

}