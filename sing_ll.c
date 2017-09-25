#include<stdio.h>

struct link 
{
	int info;
	struct link *next;
};
void createList(struct link *);
void displayList(struct link *); 

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
	int i=1;
	
	while(node != NULL)
	{
		printf("\n The value of %d node is : %d",i, node->info);
		node = node->next;
	}
	printf("\n");
}
