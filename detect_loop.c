#include <stdio.h>
#include <malloc.h>

struct node{
	struct node *next;
	int data;
};
//typedef struct struct node struct node;

void push(struct node **q, int num){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = num;
	temp->next = *q;
	*q = temp;
}

int detect_loop(struct node *q){
	struct node *fast = q, *slow = q;
	
	while(slow && fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if(fast == slow ){
			printf("LOOP FOUND\n");
			return 1;
		}
	}
	return 0;
}
// void print(struct node *q){
// 	while(q->next != NULL){
// 		print("%d->\n",q->data);
// 		q = q->next;
// 	}
// }

int main(){
	struct node *temp = NULL;
	push(&temp, 20);
	push(&temp, 4);
	push(&temp, 15);
	push(&temp, 10);
	temp->next->next->next->next = temp;
	//print(temp);
	detect_loop(temp);
}