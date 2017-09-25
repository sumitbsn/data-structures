#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *link;
} ;

struct node *start;


void push(struct node **q, int num)
{

	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = num;
	temp->link = *q;
	(*q) = temp; 
	
}

void append(struct node **q, int num)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	struct node *r = *q;
	
	temp->data = num;
	temp->link = NULL;
	
	if(*q == NULL)
	{
		*q = temp;
		return;
	}
	while(r->link != NULL)
	{
		r = r->link;
	}
	
	r->link = temp;
	return; 


}

void insert(struct node *q, int loc, int num){
	struct node *temp , *r;
	int i;
	temp = q;
	for(i = 0; i < loc; i++){
		temp = temp->link;
	}
	r = (struct node*)malloc(sizeof(struct node));
	r->data = num;
	r->link = temp->link;
	temp->link = r;
}

void delete(struct node **q, int num)
{
	struct node *temp = *q, *prev;

	if(temp != NULL && temp->data == num){
		*q = temp->link;
		free(temp);
		return;
	}
	while(temp != NULL && temp->data != num){
		prev = temp;
		temp = temp->link;
	}
	if(temp == NULL) 
		return;

	prev->link = temp->link;
	free(temp);

}

void del(struct node **q, int pos)
{
	int i = 1;
	if(*q == NULL)
		return;

	struct node *temp = *q, *a;
	if(pos == NULL){
		*q = temp->link;
		free(temp);
		return;
	}
	struct node *tail = *q;
	while(temp->link != NULL){ 
		temp = temp->link;
		if(i == pos){
			tail->link = temp->link;
			free(temp);
			return;
		}
		tail = tail->link;
	}	
}

void prnt(struct node *q)
{
	if(q == NULL)
		printf("Empty ELEMENTS in LINKED LIST\n");
	else{
		while(q->link != NULL)
		{
			printf("%d->",q->data);
			q = q->link;
		}
		printf("%d->",q->data);
		printf("\n");

	}
}


int main()
{
	struct node *tmp = NULL;
	int i, n, *arr;
	struct node *temp = NULL;
	printf("Enter the size of Link:\n");
	scanf("%d",&n);
	arr = (int *)malloc(sizeof(int) * n);
	printf("Enter the values:");
	for (i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
		push(&tmp, arr[i]);
		append(&temp, arr[i]);	
	}
	
	// push(&tmp, 11);
	// push(&tmp, 12);
	
	prnt(tmp);
	prnt(temp);
	
	insert(tmp,2,12);
	prnt(tmp);
	delete(&tmp, 4);
	prnt(tmp);
	del(&tmp, 2);
	prnt(tmp);
}