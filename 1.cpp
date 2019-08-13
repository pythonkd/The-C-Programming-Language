#include <stdio.h>
#include <malloc.h>

typedef struct node{
	
	int c;
	char a;
	long int d;
	char b;
	
}Node;

int main(void)
{
	Node* a = (Node*)malloc(sizeof(Node));
	long int b;
	printf("a = %d b = %d\n", sizeof(*a), sizeof(b));
	return 0;
}
