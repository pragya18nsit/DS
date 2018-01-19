#include <stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node  *left;
	struct node  *right;
};

struct node* newNode(int data) 
{
    struct node* node = (struct node*)
                           malloc(sizeof(struct node));
 
    node->data = data;
    node->left = NULL;
    node->right = NULL;  
    return(node);
}

void deleteTree(struct node* node) 
{
    if(node == NULL)
    	return;
    deleteTree(node->left);
    deleteTree(node->right);
    free(node);
} 

int main()
{
    struct node *root = newNode(1); 
    root->left            = newNode(2);
    root->right          = newNode(3);
    root->left->left     = newNode(4);
    root->left->right   = newNode(5); 
   
    deleteTree(root);  
    root = NULL; // this has to be done at the last.
 
    printf("\n Tree deleted ");
   
    getchar();
    return 0;
}
