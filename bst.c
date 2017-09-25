#include <stdio.h>
#include <malloc.h>

typedef struct bst {
	struct bst * left_child;
	int data;
	struct bst * right_child;
}bst;

void preorder(bst*);
void insert(bst** , int);
int delete(bst **, int);

int search(bst *bt, int num, bst **parrent, bst **current) {
	int flag = 0;
	bst *tmp = bt;
	while(tmp != NULL) {
		if(tmp->data == num) {
			flag++;
			*current = tmp;
			break;
		}
		if(tmp->data > num) {
			*parrent = tmp;
			tmp = tmp->left_child;
		}
		if(tmp->data < num) {
			*parrent = tmp;
			tmp = tmp->right_child;
		}
	}
	return flag;
}

int delete(bst **bt, int num) {
	bst *parrent = NULL;
	bst *current = NULL;
	bst *tmp = NULL;
	bst *ptmp = NULL;
	int flag = search(*bt, num, &parrent, &current);
	if(!flag)
		printf("\nELement Not Found!\n");
	else {
		if(current->left_child == NULL && current->right_child == NULL) {
			if(parrent->left_child == current) 
				parrent->left_child = NULL;
			if(parrent->right_child == current){
				parrent->right_child = NULL;}
			free(current);
		}
		if(current->left_child != NULL && current->right_child == NULL) {
			if(parrent->left_child == current) 
				parrent->left_child = current->left_child;
			if(parrent->right_child == current) 
				parrent->right_child = current->left_child;
			free(current);
		}
		if(current->left_child == NULL && current->right_child != NULL) {
			if(parrent->left_child == current) 
				parrent->left_child = current->right_child;
			if(parrent->right_child == current) 
				parrent->right_child = current->right_child;
			free(current);
		}
		if(current->left_child != NULL && current->right_child != NULL) {
			
			tmp = current->left_child;
			while(tmp->right_child != NULL) {
				ptmp = tmp;
				tmp = tmp->right_child;
			}
			current->data = tmp->data;
			ptmp->right_child = NULL;
			free(tmp);
		}
	}
}

void preorder(bst *bt) {
	if(bt != NULL) {
		printf("%d ", bt->data);
		preorder(bt->left_child);
		preorder(bt->right_child);
	}
}
void inorder(bst *bt) {
	if(bt != NULL) {
		inorder(bt->left_child);
		printf("%d ", bt->data);
		inorder(bt->right_child);
	}
}
void postorder(bst *bt) {
	if(bt != NULL) {
		postorder(bt->left_child);
		postorder(bt->right_child);
		printf("%d ", bt->data);
	}
}

void insert(bst **bt, int val) {
	if(*bt == NULL) {
		*bt = malloc(sizeof(bst ));
		(*bt)->data = val;
		(*bt)->left_child = NULL;
		(*bt)->right_child = NULL;
	}
	if((*bt)->data > val) 
		insert(&(*bt)->left_child, val);
	if((*bt)->data < val)
		insert(&(*bt)->right_child, val);
}


int main() {
	bst *bt = NULL;
	int i = 0;
	int BUFF[12] = {35 ,6 ,8, 3, 19, 56, 45, 48, 31, 40, 2, 4};
	for(i = 0; i < 12; i++) 
		insert(&bt, BUFF[i]);
	printf("inorder:\n");
	inorder(bt);
	printf("\n");
	printf("preorder:\n");
	preorder(bt);
	printf("\n");
	printf("postorder:\n");
	postorder(bt);
	printf("\n");

	delete(&bt, 35);
	printf("inorder after deletion\n");
	inorder(bt);
	
	insert(&bt, 35);
	printf("\ninorder after insertion\n");
	inorder(bt);
	delete(&bt, 40);
	printf("\ninorder after deletion\n");
	inorder(bt);
	delete(&bt, 31);
	printf("\ninorder after deletion\n");
	inorder(bt);
	printf("\n");

	return 0;
}
