#include <stdlib.h>
#include <stdio.h>

typedef int Element;
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
		error("큐 공백 에러");
	p = front;
	front = front->link;
	if (front == NULL) rear = NULL;
	e = p->data;
	free(p);
	return e;
}
Element peek() {
	if (is_empty())
		error("스택 공백 에러");
	return front->data;

}

void destroy_queue() {
	while (is_empty() == 0)
		dequeue();
}

int is_palindrome(const char* msg) {
	int i = 0;
	init_queue();

	//연결 큐에 msg 대입
	while (msg[i] != '\0') {
		//구두점 스페이스 대소문자 무시
		if (msg[i] >= 'A' && msg[i] <= 'Z') {
			enqueue(msg[i++] + 32);
		}
		else if (msg[i] >= 'a' && msg[i] <= 'z') {
			enqueue(msg[i++]);
		}
	}

	char front;
	char rear;

	while (size() > 1) {
		
	}
	
}

void main() {

}