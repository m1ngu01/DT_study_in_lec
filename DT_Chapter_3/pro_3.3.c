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
void print_stack(char msg[]) {
	int i;
	printf("%s[%2d]= ", msg, size());
	for (i = 0; i < size(); i++)
		printf("%2d ", data[i]);
	printf("\n");
}

int check_matching(char expr[]) {
	int i = 0, prev;
	char ch;

	init_stack(); // stack reset

	while (expr[i] != '\0') {
		ch = expr[i++];
		if (ch == '[' || ch == '{' || ch == '(')
			push(ch);
		else if (ch == ']' || ch == '}' || ch == ')')
		{
			if (is_empty())
			{
				return 2;
			}
			prev = pop();
			if (ch == ']' && ch == '['
				|| ch == '}' && ch == '{'
				|| ch == ')' && ch == '(')
			{
				return 3;
			}
		}
	}
	if (is_empty() == 0) { return 1; }
	return 0;
}

void main()
{
	char expr[4][80] = { "{A[(i+1)]=0;}", "if((i==0) && (j==0)",
	"A[(i+1])=0;", "A[i] =f)(;" };
	int err, i;
	for (i = 0; i < 4; i++) {
		err = check_matching(expr[i]);
		if (err == 0)
			printf(" 괄호정상: %s\n", expr[i]);
		else
			printf(" 괄호오류: %s (조건%d 위반)\n", expr[i], err);
	}
}