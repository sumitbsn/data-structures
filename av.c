#include <stdio.h>

typedef struct avl_node {
	int data;
	struct avl_node *left_child;
	struct avl_node *right_child;
	int key;
}avl_node;

int get_height(avl_node*);
int max(int, int);

void preorder(avl_node *node) {
	if(node != NULL) {
		printf("%d ", node->data);
		preorder(node->left_child);
		preorder(node->right_child);
}


int max(int a, int b) {
	return (a>b) ? a:b;
}

int get_height(avl_node *node) {
	if(node == NULL) 
		return 0;
	}
	return node->key;
}

int get_balance(avl_node *node) {
	return get_height(node->left_child) - get_height(node->right_child);
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
	T2->key = max(get_height(T2->left_child), get_height(T2->right_child)) + 1;
	
	return T1;
}

avl_node *left_rotate (avl_node *node) {
	avl_node *T1;
	avl_node *T2;
	T1 = node->right_child;
	T2 = T1->left_child;

	//perform rotation
	
	T1->left_child = node;
	node->right_child = T2;
	
	//update heights
	
	T1->key = max(get_height(T1->left_child), get_height(T2->right_child)) + 1;
	T2->key = max(get_height(T1->left_child), get_height(T2->right_child)) + 1;

	return T1;
}



avl_node * insert (avl_node *node, int val) {
	avl_node * tmp;
	if(node == NULL) {
		tmp = (avl_node *)malloc(sizeof(avl_node));
		tmp->data = val;
		tmp->left_child = NULL;
		tmp->right_child = NULL;
		tmp->key = max(get_height(tmp->left_child), get_height(tmp->right_child)) + 1;
	}

	else if(val > node->data) 
			insert(node->right_child, val);
		else 
			insert(node->left_child, val);
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
}

int main() {
	
	avl_node * node;
	int val[6] = {10,20,30,40,50,25};
	int i = 0;
	for(i = 0; i < 6; i++) 
		insert(node, val[i]);
	printf("Preorder:\n");
	preorder(node);
	
	return 0;
}

