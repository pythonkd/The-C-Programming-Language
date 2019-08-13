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


int main(void)
{
	stack p;
	init(&p);
	printf("请输入进制和要转换的数字用空格隔开\n");
	int base;
	int number;
	scanf("%d %d",&base, &number);
	int rel;
	while(number>0)
	{
		rel = number%base;
		push(&p, rel);
		number = number/base;
	}
	traversal(&p);
	return 0;
}



void traversal(stack* p)
{
	Node* curnode = p->head;
	while (curnode != p->tail)
	{
		printf("%d", curnode->val);
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
