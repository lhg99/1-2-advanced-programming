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
		printf("������ ������ �ʽ��ϴ�.");
		exit(1);
	};
	fclose(f);

	printf("�ּҷ� �����ϴ� ���α׷��Դϴ�. �޴��� �����Ͻʽÿ�.\n");

	while (1)
	{
		printf("1. ���� 2. ���� 3. �˻� 4. ��� 5. ����");
		scanf("%d", &a);

		switch (a)
		{
		case 1: //����

			printf("�̸�, ��ȭ��ȣ, �̸��� �ּҸ� �Է����ּ���.\n");
			 scanf("%s %d %s", Name, &Phone_num, Address);

			NODE *head = malloc(sizeof(NODE));
			add(head, Name, Phone_num, Address);
			break;

		case 2: //����

			printf("������ �̸�, ��ȭ��ȣ, �̸��� �ּҸ� �Է��ϼ���.\n");
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

		case 3: //�˻�

			printf("�˻��� �̸� ��ȭ��ȣ �̸��� �ּҸ� �Է��ϼ���.\n");
			 scanf("%s %d %s", b, &d, e);

			 NODE *found = findnode(head, b,d,e);
				 printf("%s %d %s\n", found->name, found->phone_num, found->address);

	
			break;

		case 4: //���

			printf("���� ��ϵ� �ּҷ��Դϴ�.");
			
			while (curr != NULL)
			{
				printf("%s %d %s", curr->name, curr->phone_num, curr->address);
				curr = curr->next;
			}
			break;

		case 5: //���� �� contacts.txt�� ���
			printf("���α׷��� �����մϴ�.");
			if (fopen_s(&f, fname, "w") != 0)
			{
				printf("������ ������ �ʽ��ϴ�.");
				exit(1);
			};

			for (curr = head->next; curr != NULL; curr = curr->next)
			{
				fprintf(f, "%s %d %s\n", curr->name, curr->phone_num, curr->address);
			}
			fclose(f);
			break;

		default: //�߸� ����������

			printf("�߸� �����ϼ̽��ϴ�.");
			break;
		}
	}

	return 0;

}