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
// Function for inorder traversal in a BST.
void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

struct node* removeAllLeaves(struct node* root){
	if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
	}
	root->left = removeAllLeaves(root->left);
    root->right = removeAllLeaves(root->right);
 
    return root;
}

int main(){
	struct node *root = createNewNode(5);
	root->left = createNewNode(3);
	root->right = createNewNode(7);
	root->left->left = createNewNode(1);
	root->left->right = createNewNode(4);
	root->right->left = createNewNode(6);
	root->right->right = createNewNode(8);
	cout << "INorder Before Deleting the leaf Node." << endl;
	inorder(root);
	removeAllLeaves(root);
	cout << "INorder after Deleting the leaf Node." << endl;
	inorder(root);
	return 0;
}
