/*
* ���α׷� ����: 5.8 ����� ť �׽�Ʈ ���α׷�
* �ǽ���¥ : 2023.05.04
* �ǽ��� : �ӹα�
* �й� : 202011309
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Student {
	int id;
	char name[32];
	char dept[32];
}Student;
typedef Student Element;

typedef struct LinkedNode {
	Element data;
	struct LinkedNode* link;
} Node;
Node* front = NULL;
Node* rear = NULL;

void error(const char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
}
int is_empty() { return front == NULL; }
void init_queue() { front = rear = NULL; }

int size() {
	Node* p;
	int count = 0;
	for (p = front; p != NULL; p = p->link)
		count++;
	return count;
}

void enqueue(Element e) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->link = NULL;

	if (is_empty()) front = rear = p;
	else {
		rear->link = p;
		rear = p;
	}
}
Element dequeue() {
	Node* p;
	Element e;

	if (is_empty())
		error("ť ���� ����");
	p = front;
	front = front->link;
	if (front == NULL) rear = NULL;
	e = p->data;
	free(p);
	return e;
}
Element peek() {
	if (is_empty())
		error("���� ���� ����");
	return front->data;

}

void destroy_queue() {
	while (is_empty() == 0)
		dequeue();
}

void print_queue(const char* msg) {
	Node* p;
	printf("%s[%2d]= ", msg, size());
	for (p = front; p != NULL; p = p->link)
		printf("%\n\t%-15d %*10s %-20s ", p->data.id, p->data.name, p->data.dept);
	printf("\n");
}

Student get_student(int id, const char* name, const char* dept) {
	Student s;
	s.id = id;
	strcpy(s.name, name);
	strcpy(s.dept, dept);
	return s;
}

void main() {
	init_queue();
	enqueue(get_student(201813007, "ȫ�浿", "��ǻ�Ͱ��а�"));
	enqueue(get_student(201813007, "ȫ�浿", "��ǻ�Ͱ��а�"));
	enqueue(get_student(201813007, "ȫ�浿", "��ǻ�Ͱ��а�"));
	enqueue(get_student(201813007, "ȫ�浿", "��ǻ�Ͱ��а�"));
	print_queue("����� �л�ť(4�� ����)");
	dequeue();
	print_queue("����� �л�ť(1�����)");
	destroy_queue();
}