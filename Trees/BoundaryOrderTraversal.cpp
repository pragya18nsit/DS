#include<stdio.h>
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

void printLeftView(struct node* root){
	if(root){
		if(root->left){
			printf("%d ", root->data);
			printLeftView(root->left);
		}
		else if(root->right){
			printf("%d ", root->data);
			printLeftView(root->right);
		}
	}
}

void printRightView(struct node* root){
	if(root){
		if(root->right){
			printRightView(root->right);
			printf("%d ", root->data);
		}
		else if(root->left){
			printRightView(root->left);
			printf("%d ", root->data);
		}
	}
}

void printLeaves(struct node* root){
	if(root){
		printLeaves(root->left);
		if(root->left == NULL && root->right == NULL){
			printf("%d ", root->data);
		}
		printLeaves(root->right);
	}
		
}


void printBoundaryTree(struct node* root){
	if (root)
    {
        printf("%d ",root->data);
		printLeftView(root->left);
		printLeaves(root);
		printRightView(root->right);
	}
}

int main(){
	struct node *root = createNewNode(5);
	root->left = createNewNode(3);
	root->right = createNewNode(7);
	root->left->left = createNewNode(1);
	root->left->right = createNewNode(4);
	root->right->left = createNewNode(6);
	root->right->right = createNewNode(8);
	
	printBoundaryTree(root);
	return 0;
}
