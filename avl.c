#include <stdio.h>
#include <stdlib.h>

typedef struct avl_node {
	int data;
	struct avl_node *left_child;
	struct avl_node *right_child;
	int key;
}avl_node;

int get_height(avl_node*);
int max(int, int);
int get_balance(avl_node*);




int max(int a, int b) {
	return (a>b) ? a:b;
}

int get_height(avl_node *node) {
	if(node == NULL) 
		return 0;
	
	return node->key;
}

int get_balance(avl_node *node) {
	return get_height(node->left_child) - get_height(node->right_child);
}

void preorder(avl_node *node) {
	if(node != NULL) {
		printf("%d ", node->data);
		preorder(node->left_child);
		preorder(node->right_child);
	}
}
	
avl_node * right_rotate (avl_node *node) {
	avl_node *T1;
	avl_node *T2;
	T1 = node->left_child;
	T2 = T1->right_child;
	
	//perform rotation 
	
	T1->right_child = node;
	node->left_child = T2;
	
	//update heights
	
	T1->key = max(get_height(T1->left_child), get_height(T1->right_child)) + 1;
	node->key = max(get_height(node->left_child), get_height(node->right_child)) + 1;
	
	return T1;
}

avl_node *left_rotate (avl_node *node) {
	avl_node *S1;
	avl_node *S2;
	S1 = node->right_child;
	S2 = S1->left_child;

	//perform rotation
	
	S1->left_child = node;
	node->right_child = S2;
	
	//update heights
	
	S1->key = max(get_height(S1->left_child), get_height(S1->right_child)) + 1;
	node->key = max(get_height(node->left_child), get_height(node->right_child)) + 1;

	return S1;
}

avl_node * new_node(int val) {
	
	avl_node * tmp = NULL;
	tmp = (avl_node *)malloc(sizeof(avl_node));
	tmp->data = val;
	tmp->left_child = NULL;
	tmp->right_child = NULL;
	tmp->key = 1;
	return tmp;
	
}

avl_node * insert (avl_node *node, int val) {
	
	if(node  == NULL)
		return new_node(val);

	if(val > node->data) 
		node->right_child = insert(node->right_child, val);
	else	 
		node->left_child = insert(node->left_child, val);
	//update heights
	
	node->key = max(get_height(node->left_child), get_height(node->right_child)) + 1;

	//check balance
	
	int balance = get_balance(node);

	//rotation
	
		if(balance > 1 && node->left_child->data > val)
			return right_rotate(node);
		if(balance < -1 && node->right_child->data < val)
			return left_rotate(node);
		if(balance > 1 && node->left_child->data < val) {
			node->left_child = left_rotate(node->left_child);
			return right_rotate(node);
		}

		if(balance < -1 && node->left_child->data > val) {
			node->right_child = right_rotate(node->right_child);
			return left_rotate(node);
		}
		return node ;
}


int main() {
	
	avl_node * node = NULL;
	int val[6] = {10,20,30,40,50,25};
	int i = 0;
	for(i = 0; i < 6; i++) 
		node  = insert(node, val[i]);
	printf("Preorder:\n");
	preorder(node);
	
	return 0;
}

