/* Tree traversal program */

#include <stdio.h>
#include <malloc.h>

struct node{
	struct node *left;
	struct node *right;
	int data;
};

struct node* New_Node(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return(temp);
}

void inorder(struct node *q){
	if(q == NULL)
		return;
	inorder(q->left);
	printf("%d\t",q->data);
	inorder(q->right);
}

void preorder(struct node *q){
	if(q == NULL)
		return;
	printf("%d\t",q->data);
	inorder(q->left);
	inorder(q->right);	

}

void postorder(struct node *q){
	if(q == NULL)
		return;
	inorder(q->left);
	inorder(q->right);
	printf("%d\t",q->data);
	
}
int height(struct node *q){
	if(q == NULL)
		return 0;
	if(q->left > q->right)
		return (q->left+1);
	else
		return (q->right +1);
}

void print_given_level(struct node *q, int level){
	if(q == NULL)
		return;
	if(level == 1)
		printf("%d\t", q->data);
	else if(level > 1){
		print_given_level(q->left, level - 1);
		print_given_level(q->right, level - 1);

	}
}
void print_level_order(struct node *root){
	int h = height(root);
	int i;
	for(i = 0; i <= h; i++)
		print_given_level(root, i);
}

int main(){
	struct node *root = New_Node(1);
	root->left = New_Node(2);
	root->right = New_Node(3);
	root->left->left = New_Node(4);
	root->left->right = New_Node(5);
	printf("\nInorder Traversal: ");
	inorder(root);
	printf("\nPreorder Traversal: ");
	preorder(root);
	printf("\nPostorder Traversal: ");
	postorder(root);
	printf("\nLevelorder Traversal: ");
	print_level_order(root);
	

}