#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

void push(struct Node**  head, int data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = data;
	new_node->next = *head;
	*head = new_node;
}
void printNthNodeFromEnd(struct Node *head, int N){
	static int i = 0;
	if(head == NULL)
		return;
	printNthNodeFromEnd(head->next,N);
	if(++i == N)
		printf("%d", head->data);
}

int main(){
	struct Node *head = NULL;
	push(&head, 4);
	push(&head,14);
	push(&head,41);
	push(&head,24);
	push(&head,54);
	printNthNodeFromEnd(head, 1);
	return 0;
}
