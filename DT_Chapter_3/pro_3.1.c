/*
프로그램 내용 : 프로그램 3.1 배열을 이용한 int 스택의 구현
실습 날짜 : 2020.04.11
학번 : 202011309
이름 : 임민규
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100	//스택 요소 저장을 위한 배열의 크기

typedef int Element;
Element data[MAX_STACK_SIZE];
int top;

void error(const char str[]) {
	printf("%s\n", str);
	exit(1);
}

void init_stack() { top = -1; }
int size() { return top + 1; }
int is_empty() { return (top == -1); }
int is_full() { return (top == MAX_STACK_SIZE - 1); }

void push(Element e)
{
	if (is_full())
	error("스택 포화 에러");
	data[++top] = e;
}
Element pop()
{
	if (is_empty())
	error("스택 공백 에러");
	return data[top--];
}
Element peek()
{
	if (is_empty())
	error("스택 공백 에러");
	return data[top];
}

void print_stack(const char msg[]) {
	int i;
	printf("%s[%2d]= ", msg, size());
	for (i = 0; i < size(); i++)
		printf("%2d ", data[i]);
	printf("\n");
}

void main() {
	int i = 0;
	init_stack();
	for (i = 1; i < 10; i++)
		push(i);
	print_stack("push 9 times");
	printf("\tpop() --> %d\n", pop());
	printf("\tpop() --> %d\n", pop());
	printf("\tpop() --> %d\n", pop());
	print_stack("stack pop 3times");

}