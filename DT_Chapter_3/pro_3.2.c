/*
���α׷� ���� : ���α׷� 3.2 �迭�� �̿��� Student ������ ����
�ǽ� ��¥ : 2020.04.11
�й� : 202011309
�̸� : �ӹα�
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100	//���� ��� ������ ���� �迭�� ũ��

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
	push(get_student(2015130007, "ȫ�浿", "��ǻ�Ͱ��а�"));
	push(get_student(2015130100, "�̼���", "�����а�"));
	push(get_student(2015130135, "�迬��", "ü����"));
	push(get_student(2015130135, "Ȳ��", "���а�"));
	print_stack("ģ�� 4�� ���� ��");
	pop();
	print_stack("ģ�� 1�� ���� ��");
}