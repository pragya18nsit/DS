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

void printGivenLevel(struct node* root,int level){
	if(root==NULL) return;
	if(level == 1)
		printf("%d ", root->data);
	else if(level >1){
		printGivenLevel(root->left, level-1);
		printGivenLevel(root->right, level-1); 
	}
}

void printGivenLevelSpiralForm(struct node* root,int level, int flag){
	if(root==NULL) return;
	if(level == 1)
		printf("%d ", root->data);
	else if(level >1  && !flag){
		printGivenLevel(root->left, level-1);
		printGivenLevel(root->right, level-1); 
	}
	else if(level >1  && flag){
		printGivenLevel(root->right, level-1);
		printGivenLevel(root->left, level-1); 
	}
}

int max(int a, int b){
	return (a>b) ? a : b;
}

int heightOfTree(struct node* root){
	if(root== NULL)
		return 0;
	return 1+ max(heightOfTree(root->left),heightOfTree(root->right));
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
	int height = heightOfTree(root);
	for(int i=1 ; i<= height; i++){
		printGivenLevel(root,i);
		printf ("\n");
	}
	
	for(int i=1 ; i<= height; i++){
		printGivenLevelSpiralForm(root,i, ltr);
		ltr = !ltr;
		printf ("\n");
	}
	return 0;
}
