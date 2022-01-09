#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct NODE
{
	struct NODE *next;
	char *name;
	int phone_num;
	char *address;
};
typedef struct NODE NODE;

void add(NODE *target, char *name, int phone_num, char *address)
{
	NODE *newnode = malloc(sizeof(NODE));
	newnode->next = target->next;
	newnode->name = name;
	newnode->phone_num = phone_num;
	newnode->address = address;

	target->next = newnode;
}

void Removenode(NODE *node, char *name, int phone_num, char *address)
{
	struct NODE *curr = node;
	struct NODE *prev = NULL;
	while (curr != NULL)
	{
		if (curr->name == name)
			if (curr->phone_num==phone_num)
				if (curr->address==address)
				{
					prev->next = curr->next;
					free(curr); 
					return;
				}

		prev = curr;        
		curr = curr->next;  
	}
}