/*
프로그램 내용 : 큐를 이용한 미팅 주선 프로그램
실습 날짜 : 2023.04.15
학번 : 202011309
이름 : 임민규
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100
#define SCANF_SIZE 30

typedef struct stname {
    char name[SCANF_SIZE];
} Name;
typedef Name Element;

typedef struct CircularQueue {
    Element data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void error(const char* str) {
    printf("%s\n", str);
    exit(1);
}

void init_queue(Queue* q) { q->front = q->rear = 0; ; }
int is_empty(Queue* q) { return q->front == q->rear;; }
int is_full(Queue* q) { return (q->rear + 1) % MAX_QUEUE_SIZE == q->front; }
int size(Queue* q) { return (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }

void enqueue(Queue* q, Element val) {
    if (is_full(q))
        error(" 큐 포화 에러");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = val;
}
Element dequeue(Queue* q) {
    if (is_empty(q))
        error(" 큐 공백 에러");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}
Element peek(Queue* q) {
    if (is_empty(q))
        error(" 큐 공백 에러");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void makeing_couple() {

    Queue man;
    init_queue(&man);
    Queue female;
    init_queue(&female);

    Element tmp = { NULL };
    char gender = NULL;

    while (1) {
        printf("고객의 이름은? (종료는 -1) >> ");
        scanf_s("%s", tmp.name, SCANF_SIZE);

        // -1 입력시 프로그램 종료
        if (strcmp(tmp.name, "-1") == 0) {
            printf("미팅 주선 프로그램을 종료합니다.");
            exit(1);
        }
        printf("성별을 입력(남자는 m, 여자는 f) >> ");
        scanf_s("%s", &gender, SCANF_SIZE);

        //남자일때
        if (gender == 'm') {
            enqueue(&man, tmp);
        }
        //여자일때
        else if (gender == 'f') {
            enqueue(&female, tmp);
        }
        else {
            printf("잘못된 입력 입니다.\n");
        }

        // 커플 만들기
        if (is_empty(&man) == 0 && is_empty(&female) == 0) {
            printf("커플 탄생 : %s와 %s\n", dequeue(&man).name, dequeue(&female).name);
        }
        else {
            printf("아직 대상자가 없습니다.\n");
        }
    }
}

void main() {
    makeing_couple();
}