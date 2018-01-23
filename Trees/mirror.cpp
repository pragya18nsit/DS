#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node  *right;
};

struct node* createNewNode(int key){
	struct node* newNode = (struct node *) malloc( sizeof(struct node) );
	newNode->data = key;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode; 	
}

struct node* mirror(struct node* root){
	if(root == NULL)
		return NULL;
	else{
		struct node* temp;
		mirror(root->left);
		mirror(root->right);	
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}

void inorder(struct node* root){
	if(root == NULL)
		return;	
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}


int main(){
	int ltr = 0;
	struct node *root = createNewNode(5);
	root->left = createNewNode(3);
	root->right = createNewNode(7);
	root->left->left = createNewNode(1);
	root->left->right = createNewNode(4);
	root->right->left = createNewNode(6);
	root->right->right = createNewNode(8);
	mirror(root);
	inorder(root);
	return 0;
}
