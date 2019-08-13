#include <stdio.h>
#include <malloc.h>

typedef struct node{
	char val;
	struct node* next;
}Node;

typedef struct s
{
	Node* head;
	Node* tail;
	int size;
}stack;

void init(stack*);
void push(stack*, char);
void traversal(stack*);
char top(stack*);
void pop(stack*);

int main(void)
{
	stack p;
	init(&p);
	char s[] = "{";
	char* t = s;
	int flag=1;
	while(*t != '\0')
	{
		if(*t=='(' || *t=='[' || *t=='{' || *t==')' || *t==']' || *t=='}')
		{
			if(*t=='(' || *t=='[' || *t=='{') push(&p, *t++);
			else if(p.size == 0)
			{
				flag=0;
				break;
			}
			else if((top(&p)=='(' && *t==')') || (top(&p)=='[' && *t==']') || (top(&p)=='{' && *t=='}'))
			{
				pop(&p);
				t++;
			}
			else
			{
				flag=0;
				break;
			}
		}
		else t++;
		
	}
	if(flag && p.size==0)
	{
		printf("true");
	}
	else printf("false");
	return 0;	
}

void pop(stack* p)
{
	Node* head = p->head;
	p->head = head->next;
	free(head);
	p->size -= 1;
}

char top(stack* p)
{
	return p->head->val;
}

void traversal(stack* p)
{
	Node* curnode = p->head;
	while(curnode != p->tail)
	{
		printf("%c  ", curnode->val);
		curnode = curnode->next;
	}
}

void push(stack* p, char value)
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
	p->tail = (Node*)malloc(sizeof(Node));
	p->size = 0;
	p->tail->next = NULL;
	p->head = p->tail;
}
