#include <stdio.h>
#include <malloc.h>

typedef struct node{
	int val;
	struct node* next;
	struct node* pre;
}Node;

typedef struct {
	Node* head;
	Node* tail;
}Link;

void init(Link*);
void insert(Link*, int);
void traversal(Link*);
void selection_sort(Link*);
void insertion_sort(Link*);

int main(void)
{
	Link p;
	init(&p);
	insert(&p, 4);
	insert(&p, 2);
	insert(&p, 1);
	insert(&p, 5);
	insert(&p, 79);
	insert(&p, 0);
	insert(&p, 1);
	insert(&p, 4);
	insert(&p, 32);
	insertion_sort(&p);
//	selection_sort(&p);
	traversal(&p);
	return 0;
}

void insertion_sort(Link* p)
{
	Node* curnode = p->head->next;
	while(curnode != p->tail)
	{
		Node* tmpnode = curnode;
		while(tmpnode->pre != p->head)
		{
			Node* prenode = tmpnode->pre;
			if(prenode->val > tmpnode->val)
			{
				int value = tmpnode->val;
				tmpnode->val = prenode->val;
				prenode->val = value;
				tmpnode = prenode;
			}
			else break;
		}
		curnode = curnode->next;
	}
}
void selection_sort(Link* p)
{
	Node* tail = p->tail;
	Node* curnode;
	Node* maxnode;
	while(tail != p->head->next)
	{
		curnode = p->head->next;
		maxnode = p->head->next;
		while(curnode!= tail)
		{
			if(curnode->val > maxnode->val)
			{
				maxnode = curnode;
			}
			curnode = curnode->next;
		}
		Node* prenode = maxnode->pre;
		prenode->next = maxnode->next;
		maxnode->next->pre = prenode;
		prenode = tail->pre;
		prenode->next = maxnode;
		maxnode->next = tail;
		maxnode->pre = prenode;
		tail->pre = maxnode;
		tail = maxnode;
	}
}

void traversal(Link* p)
{
	Node* curnode = p->head->next;
	while(curnode != p->tail)
	{
		printf("%d\n", curnode->val);
		curnode = curnode->next;
	}
}

void insert(Link* p, int value)
{
	Node* end = p->tail->pre;
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = value;
	end->next = node;
	node->pre = end;
	node->next = p->tail;
	p->tail->pre = node;
}

void init(Link* lp)
{
	lp->head = (Node*)malloc(sizeof(Node));
	lp->tail = (Node*)malloc(sizeof(Node));
	lp->head->next = lp->tail;
	lp->head->pre = lp->tail;
	lp->tail->next = lp->head;
	lp->tail->pre = lp->head;
	lp->head->val = NULL;
	lp->tail->val = NULL;
}
