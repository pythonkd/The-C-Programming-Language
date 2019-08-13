#include <stdio.h>
#include <malloc.h>


typedef struct node{
	int val;
	struct node* next;
}Node;

typedef struct n{
	Node* head;
	Node* tail;
	int size;
}stack;

void init(stack*);
void push(stack*, int);
void traversal(stack*);
int del_element(stack*);
void top(stack*);

int main(void)
{
	stack p;
	init(&p);
	push(&p, 1);
	push(&p, 5);
	push(&p, 8);
	push(&p, 2);
	push(&p, 9);
	push(&p, 0);
	push(&p, 7);
	traversal(&p);
	int data = del_element(&p);
	printf("É¾³ýµÄÔªËØÊÇ:%d\n", data);
	top(&p);
	printf("size = %d",p.size);
	return 0;
}

void top(stack* p)
{
	printf("top = %d\n", p->head->next->val);
}

int del_element(stack* p)
{
	Node* curnode = p->head->next;
	int data = curnode->val;
	p->head->next = curnode->next;
	p->size = p->size - 1;
	free(curnode);
	return data;
}

void traversal(stack* p)
{
	Node* curnode = p->head->next;
	while(curnode != p->tail)
	{
		printf("%d  ", curnode->val);
		curnode = curnode->next;
	}
}

void push(stack* p, int value)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = value;
	Node* head = p->head->next;
	p->head->next = node;
	node->next = head;
	p->size = p->size + 1;
}
void init(stack* p)
{
	p->head = (Node*)malloc(sizeof(Node));
	p->tail = (Node*)malloc(sizeof(Node));
	p->head->next = p->tail;
	p->size = 0;
}
