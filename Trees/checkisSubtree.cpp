#include<stdio.h>
#include<stdlib.h>
#include<iostream>
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

int identicalTrees( struct node* root1, struct node* root2){
	if(root1 == NULL && root2 == NULL){
		return 1;
	}
	else if(root1 != NULL && root2 != NULL){
		return (root1->data == root2->data && identicalTrees(root1->left,root2->left)  && identicalTrees(root1->right,root2->right));
	}
	return 0;
}


int isSubTree( struct node* root1, struct node* root2){
	if (root1 == NULL)
        return true;
 
    if (root2 == NULL)
        return false;
        
	if (identicalTrees(root1, root2))
        return true;
        
	if(root1 != NULL && root2 != NULL){
		return isSubTree(root1->left,root2)  || isSubTree(root1->right,root2);
	}
	return 0;
}

int main(){
	struct node *root1 = createNewNode(5);
	root1->left = createNewNode(3);
	root1->right = createNewNode(7);
	root1->left->left = createNewNode(1);
	root1->left->right = createNewNode(4);
	root1->right->left = createNewNode(6);
	root1->right->right = createNewNode(8);
	
	struct node *root2 = createNewNode(5);
	root2->left = createNewNode(3);
	root2->right = createNewNode(7);

	
	int identical = isSubTree(root1, root2);
	cout << "The given trees are "  << ((identical ==1) ? "" : "not" )<< " isSubTree";
	return 0;
}
