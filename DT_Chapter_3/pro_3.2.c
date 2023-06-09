/*
프로그램 내용 : 프로그램 3.2 배열을 이용한 Student 스택의 구현
실습 날짜 : 2020.04.11
학번 : 202011309
이름 : 임민규
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100	//스택 요소 저장을 위한 배열의 크기

typedef struct Student_t {
	int id;
	char name[32];
	char dept[32];
} Student;
typedef Student Element;

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
		printf("\n\t%-15d %-10s %-20s", data[i].id, data[i].name, data[i].dept);
	printf("\n");
}

Student get_student(int id, const char* name, const char* dept)
{
	Student s;
	s.id = id;
	strcpy(s.name, name);
	strcpy(s.dept, dept);
	return s;
}
void main()
{
	init_stack();
	push(get_student(2015130007, "홍길동", "컴퓨터공학과"));
	push(get_student(2015130100, "이순신", "기계공학과"));
	push(get_student(2015130135, "김연아", "체육과"));
	push(get_student(2015130135, "황희", "법학과"));
	print_stack("친구 4명 삽입 후");
	pop();
	print_stack("친구 1명 삭제 후");
}