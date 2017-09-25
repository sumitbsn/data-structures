#include <stdio.h>
#include <malloc.h>

typedef struct ll {
	int data;
	struct ll *next;
}LL;

int ll_insert(LL **, int );
int ll_display(LL *);
int ll_reverse(LL **);

int main() {
	
	int i;
	int data[5] = {10, 15, 20, 25, 30};
	LL *head = NULL;
	for(i = 0; i < 5; i++)
		ll_insert(&head, data[i]);
	ll_display(head);
	printf("reverted LL\n");
	ll_reverse(&head);
	ll_display(head);
	printf("\nreverse Function called\n");
	//ll_display_rev(&head);
	ll_reverse_recursion(&head);
	printf("\ndisplay function called\n");
	ll_display(head);

	return 0;
}

int ll_insert(LL **ptr, int val) {
	
	if(*ptr == NULL) {
		*ptr = malloc(sizeof(LL));
		(*ptr)->data = val;
		(*ptr)->next = NULL;
	}
	else {
		LL *tmp = *ptr;
		while( tmp->next != NULL ) tmp = tmp->next;
		ll_insert(&(tmp->next), val);
	}
}
			
int ll_display(LL *ptr) {
	LL *temp = ptr;
	while( temp != NULL ) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

int ll_reverse(LL **head) {
	
	LL *prev = NULL;
	LL *current = *head;
	LL *next;

	while(current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

int ll_display_rev(LL **head) {
	LL *tmp = *head;
	if( tmp == NULL) {
		return;
	}
	printf("%d ", tmp->data);
	ll_display_rev(&(tmp->next));
}

int ll_reverse_recursion(LL **head) {
	LL *tmp = *head;
	if(tmp->next == NULL) {
		*head = tmp;
		return;
	}
	//printf("%d ", tmp->data);
	ll_reverse_recursion(&(tmp->next));
	tmp->next->next = tmp;
	tmp->next = NULL;
}










