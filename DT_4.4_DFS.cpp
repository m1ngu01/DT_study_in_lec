﻿#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
	int x;
	int y;
}Location2D;
typedef Location2D Element;

Element data[MAX_QUEUE_SIZE];
int front;
int rear;

#define MAP_SIZE 6
char map[MAP_SIZE][MAP_SIZE]{
	{'1','1','1','1','1','1'},
	{'1','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'}
};

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
		error(" 큐 포화 에러");
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = val;
}
Element dequeue() {
	if (is_empty())
		error(" 큐 공백 에러");
	front = (front + 1) % MAX_QUEUE_SIZE;
	return data[front];
}
Element peek() {
	if (is_empty())
		error(" 큐 공백 에러");
	return data[(front + 1) % MAX_QUEUE_SIZE];
}

void add_front(Element val) {
	if (is_full())
		error(" 덱 포화 에러");
	data[front] = val;
	front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}
Element delete_rear() {
	Element ret;
	if (is_empty())
		error(" 덱 공백 에러");
	ret = data[rear];
	rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return ret;
}
Element get_rear() {
	if (is_empty())
		error(" 덱 공백 에러");
	return data[rear];
}

void printf_deque(const char msg[]) { print_queue(msg); }

/*
max function zone
*/
Location2D getLocation2D(int x, int y) {
	Location2D p;
	p.x = x;
	p.y = y;
	return p;
}

int is_valid(int x, int y) {
	if (x < 0 || y < 0 || x >= MAP_SIZE || y >= MAP_SIZE) return 0;
	else return map[y][x] == '0' || map[y][x] == 'x';
}

int DFS()
{
	int x, y;
	Location2D here;
	init_deque();
	add_rear(getLocation2D(0, 1));
	printf("DFS: ");
	while (is_empty() == 0) {
		here = delete_rear();
		printf("(%2d, %2d)", here.x, here.y);
		x = here.x;
		y = here.y;
		if (map[y][x] == 'x') return 1;
		else {
			map[y][x] = '.';
			if (is_valid(x - 1, y)) add_rear(getLocation2D(x - 1, y));
			if (is_valid(x + 1, y)) add_rear(getLocation2D(x + 1, y));
			if (is_valid(x, y - 1)) add_rear(getLocation2D(x, y - 1));
			if (is_valid(x, y + 1)) add_rear(getLocation2D(x, y + 1));
		}
	}
	return 0;
}

void main()
{
	printf("->%s\n", DFS() ? "O" : "X");
}