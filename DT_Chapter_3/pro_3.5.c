/*
프로그램 내용 : 프로그램 3.5 중위 수식의 후위 표기 변환 프로그램
실습 날짜 : 2020.04.11
학번 : 202011309
이름 : 임민규
*/
#include <stdio.h>

#define MAX_STACK_SIZE 100

typedef int Element;
Element data[MAX_STACK_SIZE];
int top;

void init_stack() { top = -1; }
int size() { return top + 1; }
int is_empty() { return (top == -1); }
int is_full() { return (top == MAX_STACK_SIZE - 1); }

void push(Element e)
{
	if (is_full())
		printf("스택 포화 에러");
	//error("스택 포화 에러");
	data[++top] = e;
}
Element pop()
{
	if (is_empty())
		printf("스택 포화 에러");
	//error("스택 공백 에러");
	return data[top--];
}
Element peek()
{
	if (is_empty())
		printf("스택 포화 에러");
	//error("스택 공백 에러");
	return data[top];
}
void print_stack(const char msg[]) {
	int i;
	printf("%s[%2d]= ", msg, size());
	for (i = 0; i < size(); i++)
		printf("%2d ", data[i]);
	printf("\n");
}

static int precedence(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

void infix_to_postfix(char expr[]) {

	int i = 0;
	char c, op;

	init_stack();

	while (expr[i] != '\0') {
		c = expr[i++];
		if ((c >= '0' && c <= '9')) {
			printf("%c ", c);
		}
		else if (c == '(') {
			push(c);
		}
		else if (c == ')') {
			while (is_empty() == 0) {
				op = pop();
				if (op == '(') { break; }
				else { printf("%c", op); }
			}
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			while (is_empty() == 0) {
				op = peek();
				if (precedence(c) <= precedence(op)) {
					printf("%\c", op);
					pop();
				}
				else { break; }
			}
			push(c);
		}
	}
	while (is_empty() == 0) {
		printf("%c", pop());
	}
	printf("\n");
}

void main()
{
	char expr[2][80] = { "8/2-3+(3*2)", "1/2* 4 * (1/4)" };
	printf("중위수식: %s ==> 후위수식:", expr[0]);
	infix_to_postfix(expr[0]);
	printf("중위수식: %s ==> 후위수식:", expr[1]);
	infix_to_postfix(expr[1]);
}