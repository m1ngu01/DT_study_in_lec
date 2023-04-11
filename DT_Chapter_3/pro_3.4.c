/*
프로그램 내용 : 프로그램 3.4 후위 표기 수식의 계산 프로그램
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


double calc_postfix(char expr[]) {
	char c;
	double val, val1, val2;
	int i = 0;
	init_stack();
	while (expr[i] != '\0') {
		c = expr[i++];
		if (c >= '0' && c <= '9') {
			val = c - '0';
			push(val);
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			val2 = pop();
			val1 = pop();
			switch (c) {
			case '+': push(val1 + val2); break;
			case '-': push(val1 - val2); break;
			case '*': push(val1 * val2); break;
			case '/': push(val1 / val2); break;
			}
		}
	}
	return pop(); //계산이 완료된 결과는 스택에 유일하게 남아있다.
}


void main() {
	char expr[2][80] = { "8 2 / 3- 3 2 * +", "1 2 / 4 * 1 4 / *" };
	printf("수식: %s = %lf\n", expr[0], calc_postfix(expr[0]));
	printf("수식: %s = %lf\n", expr[1], calc_postfix(expr[1]));
}