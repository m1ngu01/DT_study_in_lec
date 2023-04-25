/*
* ���α׷� ����: 6.4 �迭�� �̿��� ����Ʈ ��ü ���α׷�
* �ǽ���¥ : 2023.04.25
* �ǽ��� : �ӹα�
* �й� : 202011309
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int Element;
Element data[MAX_LIST_SIZE];
int length = 0;

void error(const char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
}

void init_list() { length = 0;}
void clear_list() { length = 0; }
int is_empty() { return length == 0; }
int is_full() { return length == MAX_LIST_SIZE; }
int get_entry(int id) { return data[id]; }
void replace(int id, Element e) { data[id] = e; }
int size() { return length; }

void insert(int pos, int e) {
	int i;
	if (is_full() == 0 && pos >= 0 && pos <= length) {
		for (i = length; i > pos; i--)
			data[i] = data[i - 1];
		data[pos] = e;
		length++;
	}
	else error("��ȭ���� ���� �Ǵ� ���� ��ġ ����");
}

void del (int pos) {
	int i;
	if (is_empty() == 0 && 0<=pos && pos < length) {
		for (i = pos+1; i < length; i++)
			data[i-1] = data[i];
		length--;
	}
	else error("������� ���� �Ǵ� ���� ��ġ ����");
}

int find(Element e) {
	int i;
	for (i = 0; i < length; i++)
		if (data[i] == e) return i;
	return -1;
}

void print_list(const char* msg) {
	int i;
	printf("%s[%2d]: ", msg, length);
	for (i = 0; i < length; i++)
		printf("%2d ", data[i]);
	printf("\n");
}

void main() {
	init_list();
	insert(0, 10);
	insert(0, 20);
	insert(1, 30);

	insert(size(), 40);
	insert(2, 50);
	print_list("�迭�� ������ List(����x5)");

	replace(2, 90);
	print_list("�迭�� ������ List(��üx1)");

	del(2);
	del(size() - 1);
	del(0);
	print_list("�迭�� ������ List(����x3)");

	clear_list();
	print_list("�迭�� ������ List(������)");
}