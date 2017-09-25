///* Program to illustrate the reverse of a single linked list using iterative and recurssion method */
///* http://www.geeksforgeeks.org/write-a-function-to-reverse-the-nodes-of-a-linked-list/ *

#include<stdio.h>

struct link 
{
	int info;
	struct link *next;
};
void createList(struct link *);
void displayList(struct link *);
void reverseList(struct link **);
void reverseListRecursive(struct link **); 

int main()
{
	struct link *node = (struct link*) malloc (sizeof(struct link));
	if(node == NULL)
	{
		printf("\n Malloc Error \n");
		return;
	}
	createList(node);
	displayList(node);
	printf("\n REVERSE LIST- Iterative\n");
	reverseList(&node);
	displayList(node);
	printf("\n REVERSE LIST- Recursive\n");
	reverseListRecursive(&node);
	displayList(node);
}

void createList(struct link *node)
{
	int i=1, ch;
	printf("\nEnter the value to node %d: ",i);
	scanf("%d",&node->info);
	node->next = NULL;
	i++;
	
	printf("\nPress 1 to continue : ");
	scanf("%d",&ch);
	
	while(ch == 1)
	{
			
		node->next = (struct link*) malloc (sizeof(struct link));
		node = node->next;
		if(node == NULL)
		{
			printf("\n Malloc Error \n");
			return;
		}
		printf("\nEnter the value to node %d: ",i);
		scanf("%d",&node->info);
		node->next = NULL;
		i++;
		printf("\nPress 1 to continue : ");
		scanf("%d",&ch);
	}	
}

void displayList(struct link *node)
{
	
	while(node != NULL)
	{
		printf("%d", node->info);
		if(node->next != NULL)
			printf("-->");
		node = node->next;
	}
	printf("\n");
}

void reverseList(struct link **node)
{
	struct link *prev = NULL;
	struct link *curr = *node;
	struct link *nxt;

	while(curr != NULL)
	{
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
	}
	*node = prev;
}	

void reverseListRecursive(struct link **node)
{
	struct link *first = *node;
	struct link *rest = first->next;

	if(first == NULL)
		return;
	if(rest == NULL)
		return;

	reverseListRecursive(&rest);
	first->next->next = first;
	first->next = NULL;

	*node = rest;
} 


