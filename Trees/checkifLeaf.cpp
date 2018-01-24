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

int checkifleafNode(struct node* root){
	if(root == NULL)
		return NULL;
	checkifleafNode(root->left);
	checkifleafNode(root->right);
	if(root->left == NULL && root->right == NULL)
		return 1;
	return 0;
}

//int countLeaves(struct node* root){
//	if(root == NULL)
//		return NULL;
//	if(root->left == NULL && root->right==NULL)      
//    	return 1;            
//  	else
//    	return countLeaves(root->left)+
//           countLeaves(root->right);  
//}

bool isLeaf(node* root)
{
	return (root->left==NULL && root->right==NULL);
}

void countLeaves(node* root, int &count)
{
	if(root==NULL){
		return;
	}
	if(isLeaf(root)){
		count++;
	}
	countLeaves(root->left, count);
	countLeaves(root->right, count);
}


void printLeaves(struct node* root){
	if(root == NULL)
		return;
	if(root->left == NULL && root->right==NULL)      
    	printf("%d ", root->data);          
	printLeaves(root->left);
    printLeaves(root->right);  
       
}

int main(){
	struct node *root = createNewNode(5);
	root->left = createNewNode(3);
	root->right = createNewNode(7);
	root->left->left = createNewNode(1);
	root->left->right = createNewNode(4);
	root->right->left = createNewNode(6);
	root->right->right = createNewNode(8);
	int isleaf = checkifleafNode(root->right->right);
	int leavesCount = 0;
	countLeaves(root, leavesCount);
	cout <<"the given node is  "<< (isleaf ? "" : "not ") << "a leaf node";
	printf("\n");
	cout <<"the number of leaf nodes is  "<< leavesCount;
	printf("\n");
	cout <<"the leaf nodes in sequence are  ";
	printLeaves(root);
	return 0;
}
