#include <stdlib.h>
#include <stdio.h>

typedef int Element;
typedef struct LinkedNode {
	Element data;
	struct LinkedNode* link;
} Node;
Node* top = NULL;

void error(const char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
}
int is_empty() { return top == NULL; }
void init_stack() { top == NULL; }
int size()
{
	Node* p;
	int count = 0;
	for (p = top; p != NULL; p = p->link)
		count++;
	return count;
}
void push(Element e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->link = top; // (1)
	top = p; // (2)
}
Element pop()
{
	Node* p;
	Element e;
	if (is_empty()) error("에러");
	p = top; // (1)
	top = p->link; // (2)
	e = p->data;
	free(p);
	return e;
}
Element peek() {
	if (is_empty())
		error("스택 공백 에러");
	return top->data;

}
void destory_stack() {
	while (is_empty() == 0)
		pop();
}

void print_stack(const char* msg) {
	Node* p;
	printf("%s[%2d]= ", msg, size());
	for (p = top; p != NULL; p = p->link)
		printf("%2d ", p->data);
	printf("\n");
}

void main() {
	int i;

	init_stack();
	for (i = 1; i < 10; i++)
		push(i);
	print_stack("연결된 스택 push 9회");
	printf("\tpop() --> %d\n", pop());
	printf("\tpop() --> %d\n", pop());
	printf("\tpop() --> %d\n", pop());
	print_stack("연결된스택 pop 3회");
	destory_stack();
	print_stack("연결된스택 destroy");

}