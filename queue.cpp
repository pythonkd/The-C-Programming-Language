#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	int val;
	struct node* next;
}Node;

typedef struct q
{
	Node* head;
	Node* tail;
	int size;
}queue;

void init(queue*);
void push(queue*, int);
void traversal(queue*);
void pop(queue* p);
void top(queue* p);

int main(void)
{
	queue q;
	init(&q);
	push(&q, 3);
	push(&q, 4);
	push(&q, 5);
	push(&q, 6);
	pop(&q);
	top(&q);
	traversal(&q);
	return 0;
}

void top(queue* q)
{
	Node* head = q->head->next;
	printf("top:%d\n", head->val);
}

void pop(queue* q)
{
	Node* head = q->head->next;
	q->head->next = head->next;
	printf("pop:%d\n", head->val);
	free(head);
	q->size -= 1;
}

void traversal(queue* q)
{
	Node* curnode = q->head->next;
	while(curnode != NULL)
	{
		printf("%d\n", curnode->val);
		curnode = curnode->next;
	}
}

void push(queue* q, int value)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = value;
	node->next = NULL;
	q->tail->next = node;
	q->tail = node;
	q->size += 1;
}

void init(queue* q)
{
	q->head = (Node*)malloc(sizeof(Node));
	q->size = 0;
	q->tail = q->head;
	q->head->next = NULL;
}
