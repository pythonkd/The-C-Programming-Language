#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	int val;
	struct node* next;
}Node;

typedef struct s
{
	Node* head;
	Node* tail;
	int size;
}stack;

void init(stack*);
void push(stack*, int);
void traversal(stack*);
void pop(stack*);
void top(stack*);

int main(void)
{
	stack p;
	init(&p);
	push(&p, 2);
	push(&p, 3);
	push(&p, 4);
	push(&p, 5);
	push(&p, 6);
	pop(&p);
	pop(&p);
	top(&p);
	printf("size:%d\n", p.size);
	traversal(&p);
	return 0;
}

void top(stack* p)
{
	Node* curnode = p->head;
	printf("top:%d\n", curnode->val);
}

void pop(stack* p)
{
	Node* head = p->head;
	p->head = head->next;
	p->size -= 1;
	printf("pop:%d\n", head->val);
}

void traversal(stack* p)
{
	Node* curnode = p->head;
	while (curnode != p->tail)
	{
		printf("%d  ", curnode->val);
		curnode = curnode->next;
	}
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
	p->size = 0;
	p->tail = p->head;
	p->head->next = NULL;
}
