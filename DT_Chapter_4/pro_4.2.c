#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef int Element;
Element data[MAX_QUEUE_SIZE];
int front;
int rear;

//forward declaration
void enqueue(Element val);
Element dequeue();
Element peek();

void init_queue() { front = rear = 0; ; }
int is_empty() { return front == rear;; }
int is_full() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
int size() { return (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }
void init_deque() { init_queue(); }
void add_rear(Element val) { enqueue(val); }
Element delete_front() { return dequeue(); }
Element get_front() { return peek(); }

void error(const char str[]) {
	printf("%s\n", str);
	exit(1);
}
void print_queue(const char msg[]) {
	int i, maxi = rear;
	if (front >= rear) maxi += MAX_QUEUE_SIZE;
	printf("%s[% 2d] = ", msg, size());
	for (i = front + 1; i <= maxi; i++)
		printf("%2d ", data[i % MAX_QUEUE_SIZE]);
	printf("\n");
}
void enqueue(Element val) {
	if (is_full())
		error(" ť ��ȭ ����");
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = val;
}
Element dequeue() {
	if (is_empty())
		error(" ť ���� ����");
	front = (front + 1) % MAX_QUEUE_SIZE;
	return data[front];
}
Element peek() {
	if (is_empty())
		error(" ť ���� ����");
	return data[(front + 1) % MAX_QUEUE_SIZE];
}

void add_front(Element val) {
	if (is_full())
		error(" �� ��ȭ ����");
	data[front] = val;
	front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}
Element delete_rear() {
	Element ret;
	if (is_empty())
		error(" �� ���� ����");
	ret = data[rear];
	rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return ret;
}
Element get_rear() {
	if (is_empty())
		error(" �� ���� ����");
	return data[rear];
}

void printf_deque(const char msg[]) { print_queue(msg); }

void main()
{
	int i;
	init_deque();
	for (i = 1; i < 10; i++) {
		if (i % 2) add_front(i);
		else add_rear(i);
	}
	print_queue("���� �� Ȧ��-¦�� ");
	printf("\tdelete_front() --> %d\n", delete_front());
	printf("\tdelete_rear () --> %d\n", delete_rear());
	printf("\tdelete_front() --> %d\n", delete_front());
	print_queue("���� �� ����-Ȧ¦Ȧ");
}