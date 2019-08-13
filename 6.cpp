#include <stdio.h>
typedef struct node
{
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

int main(void)
{
	char a[30];
	stack p;
	init(&p);
	scanf("%s", a);
	while (a!='\0')
	{
		if(a=='[' || a=='(' || a== '{')
		{
			push(p, *a);
			a++;
		}
		else if(a==']' || a=='}' || a==')')
		{
			if(p.size==0) 
			{
				printf("false\n");
				break;	
			}
			if 
		}
	}
	return 0;
}

void top(stack* p)
{
	Node* curnode = p->head;
	return curnode->val;
}

void init(stack* p)
{
	p->head = (Node*)malloc(sizeof(Node));
	p->size = 0;
	p->tail = p->head;
	p->head->next = NULL;
}
