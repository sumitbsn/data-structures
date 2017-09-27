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
}