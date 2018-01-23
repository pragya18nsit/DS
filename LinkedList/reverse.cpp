#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

void print(struct node* head){
	struct node* temp = head;
	while(temp){
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void insert(struct node** head_ref, int new_data){
	 struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
            
    /* put in the data  */
    new_node->data  = new_data;
                
    /* link the old list off the new node */
    new_node->next = (*head_ref);    
        
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

void reverse(struct node** head){
	struct node* prev = NULL;
	struct node* current = *head;
	struct node* next;
	while(current){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}	
	*head = prev;
}

int main(){
	struct node* head = NULL;
	insert(&head,2);
	insert(&head,12);
	insert(&head,22);
	insert(&head,32);
	print(head);
	printf("\n");
	reverse(&head);
	print(head);
}
