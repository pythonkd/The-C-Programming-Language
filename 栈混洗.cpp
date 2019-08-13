#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node* next;
}Node;

typedef struct s
{
	Node* head;
	Node* tail;
	Node* size;
}stack;

void init(stack*);
void push(stack*, int);
int top(stack*);
int pop(stack*);


int main(void)
{
	stack f_stack;
	init(&f_stack);
	push(&f_stack, 5);
	push(&f_stack, 4);
	push(&f_stack, 3);
	push(&f_stack, 2);
	push(&f_stack, 1);
	
	stack tmp_stack;
	init(&tmp_stack);
	stack s_stack;
	init(&s_stack);
	push(&s_stack, 4);
	push(&s_stack, 3);
	push(&s_stack, 5);
	push(&s_stack, 1);
	push(&s_stack, 2);
	
	int f_data;
	int flag = 1;
	while(s_stack.size!=0)
	{
		f_data = pop(&f_stack);
		push(&tmp_stack, f_data);
		while(tmp_stack.size!=0 && top(&tmp_stack)==top(&s_stack))
		{
			pop(&tmp_stack);
			pop(&s_stack);
		}
		if(f_stack.size==0 && tmp_stack.size!= 0)
		{
			flag = 0;
			break;
		}
	}
	
	if(flag==0 || tmp_stack.size!=0)
	{
		printf("false");
	}
	else printf("true");
	return 0;
}

int pop(stack* p)
{
	Node* head = p->head;
	int data = head->val;
	p->head = head->next;
	free(head);
	p->size -= 1;
	return data;
}

int top(stack* p)
{
	return p->head->val;
}

void push(stack* p, int value)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = value;
	node->next = p->head;
	p->head = node;
	p->size += 1;
}

 void init(stack* p)
 {
 	p->head = (Node*)malloc(sizeof(Node));
 	p->tail = p->head;
 	p->tail->next = NULL;
 	p->size = 0;
 }
