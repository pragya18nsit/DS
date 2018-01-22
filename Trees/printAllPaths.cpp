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


void printPath(int path[],int pathlen){
	for(int i=0; i< pathlen; i++){
		printf("%d ",path[i]);
	}
	printf("\n");
}

void printAllPaths(struct node* root,int path[],int pathlen){
	 	if (root==NULL) return;
	 	
	 	path[pathlen++] = root->data;
		if(root->left == NULL  && root->right == NULL)
			printPath(path,pathlen);
		else{
			printAllPaths(root->left,path,pathlen);
			printAllPaths(root->right,path,pathlen);
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
	int path[1000];
	printAllPaths(root,path,0);
	return 0;
}
