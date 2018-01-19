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

int findLCA(struct node* root, int n1, int n2) 
{
    if(root == NULL)
    	return;
    
    if (root->key == n1 || root->key == n2)
        return root;
 
 
    Node * left_lca = findLCA(root->left,n1,n2);
    
    Node * right_lca = findLCA(root->right,n1,n2);
    
    if(left_lca   && right_lca)
    	return root;
    
    return (left_lca != NULL)? left_lca: right_lca;
} 

int max(int n1, int n2){
	if(n1> n2)
		return n1;
	return n2;
}

int depth(struct node *root){
	if(root == NULL)
		return 0;
	
	return 1+ max(depth(root->left),depth(root->right));
}

bool identical(struct node *root1,struct node *root2){
	if(root1 == NULL && root2 == NULL)
		return true;
	else if(root1 != NULL && root2 != NULL)
	{
		return root1->data == root2->data && (root1->left,root2->left)&&
            identical(root1->right, root2->right);
	}	
    return 0;
}

int size(struct node *root){
	if(root == NULL)
		return 0;
	return 1+ size(root->left) + size(root->right);
}

bool hasPathSum(struct node* node, int sum)
{
  /* return true if we run out of tree and sum==0 */
  if (node == NULL)
  {
     return (sum == 0);
  }
  
  else
  {
    bool ans = 0;  
  
    /* otherwise check both subtrees */
    int subSum = sum - node->data;
  
    /* If we reach a leaf node and sum becomes 0 then return true*/
    if ( subSum == 0 && node->left == NULL && node->right == NULL )
      return 1;
  
    if(node->left)
      ans = ans || hasPathSum(node->left, subSum);
    if(node->right)
      ans = ans || hasPathSum(node->right, subSum);
  
    return ans;
  }
}

bool isBalanced(struct node *root)
{
   int lh; /* for height of left subtree */
   int rh; /* for height of right subtree */ 
 
   /* If tree is empty then return true */
   if(root == NULL)
    return 1; 
 
   /* Get the height of left and right sub trees */
   lh = height(root->left);
   rh = height(root->right);
 
   if( abs(lh-rh) <= 1 &&
       isBalanced(root->left) &&
       isBalanced(root->right))
     return 1;
 
   /* If we reach here then tree is not height-balanced */
   return 0;
}

int diameter(struct node * tree)
{
   /* base case where tree is empty */
   if (tree == NULL)
     return 0;
 
  /* get the height of left and right sub-trees */
  int lheight = height(tree->left);
  int rheight = height(tree->right);
 
  /* get the diameter of left and right sub-trees */
  int ldiameter = diameter(tree->left);
  int rdiameter = diameter(tree->right);
 
  /* Return max of following three
   1) Diameter of left subtree
   2) Diameter of right subtree
   3) Height of left subtree + height of right subtree + 1 */
  return max(lheight + rheight + 1, max(ldiameter, rdiameter));
} 


int isSumProperty(struct node* node)
{
  /* left_data is left child data and right_data is for right 
     child data*/
  int left_data = 0,  right_data = 0;
 
  /* If node is NULL or it's a leaf node then
     return true */
  if(node == NULL ||
     (node->left == NULL && node->right == NULL))
    return 1;
  else
  {
    /* If left child is not present then 0 is used
       as data of left child */
    if(node->left != NULL)
      left_data = node->left->data;
 
    /* If right child is not present then 0 is used
      as data of right child */
    if(node->right != NULL)
      right_data = node->right->data;
 
    /* if the node and both of its children satisfy the
       property return 1 else 0*/
    if((node->data == left_data + right_data)&&
        isSumProperty(node->left) &&
        isSumProperty(node->right))
      return 1;
    else
      return 0;
  }
}

void leftViewUtil(struct node *root, int level, int *max_level)
{
    // Base Case
    if (root==NULL)  return;
 
    // If this is the first node of its level
    if (*max_level < level)
    {
        printf("%d\t", root->data);
        *max_level = level;
    }
 
    // Recur for left and right subtrees
    leftViewUtil(root->left, level+1, max_level);
    leftViewUtil(root->right, level+1, max_level);
}
 
// A wrapper over leftViewUtil()
void leftView(struct node *root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}
 
 
 


int main()
{
    struct node *root = newNode(1); 
    root->left            = newNode(2);
    root->right          = newNode(3);
    root->left->left     = newNode(4);
    root->left->right   = newNode(5); 
   
    findLCA(root,4,5);  
    root = NULL; // this has to be done at the last.
 
    printf("\n Tree deleted ");
   
    getchar();
    return 0;
}
