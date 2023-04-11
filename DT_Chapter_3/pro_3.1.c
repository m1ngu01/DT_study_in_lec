/*
���α׷� ���� : ���α׷� 3.1 �迭�� �̿��� int ������ ����
�ǽ� ��¥ : 2020.04.11
�й� : 202011309
�̸� : �ӹα�
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100	//���� ��� ������ ���� �迭�� ũ��

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
	error("���� ��ȭ ����");
	data[++top] = e;
}
Element pop()
{
	if (is_empty())
	error("���� ���� ����");
	return data[top--];
}
Element peek()
{
	if (is_empty())
	error("���� ���� ����");
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