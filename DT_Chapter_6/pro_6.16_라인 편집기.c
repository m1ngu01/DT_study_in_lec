/*
* 프로그램 내용: 6.17 리스트를 이용한 라인 편집기 프로그램
* 실습날짜 : 2023.04.25
* 실습자 : 임민규
* 학번 : 202011309
*/


#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR_PER_LINE 1000

typedef struct Line {
	char str[MAX_CHAR_PER_LINE];
} Line;
typedef Line Element;
typedef struct LinkedNode {
	Element data; // 데이터 필드
	struct LinkedNode* link; // 링크 필드
} Node;
Node* head;

void init_list() { head = NULL; }
int is_empty() { return head == NULL; }
Node* get_entry(int pos) {
	Node* p = head;
	int i;
	for (i = 0; i < pos; i++, p = p->link)
		if (p == NULL) return NULL;
	return p;
}
int size()
{
	Node* p;
	int count = 0;
	for (p = head; p != NULL; p = p->link)
		count++;
	return count;
}
void replace(int pos, Element e) {
	Node* node = get_entry(pos);
	if (node != NULL)
		node->data = e;
}

void insert_next(Node* prev, Node* n)
{
	if (n != NULL) {
		n->link = prev->link;
		prev->link = n;
	}
}
void insert(int pos, Element val)
{
	Node* new_node, * prev;
	new_node = (Node*)malloc(sizeof(Node));
	if (new_node != NULL) {
		new_node->data = val;
		new_node->link = NULL;
	}
	if (head == NULL)
		head = new_node;
	else {
		prev = get_entry(pos - 1);
		if (prev != NULL)
			insert_next(prev, new_node);
	}
}

Node* remove_next(Node* prev)
{
	Node* removed = prev->link;
	if (removed != NULL)
		prev->link = removed->link;
	return removed;
}
void del(int pos) {
	Node* prev, * removed;
	if
		(pos == 0 && is_empty() == 0) {
		removed = head;
		head = head->link;
		free(removed);

	}
	else
	{
		prev = get_entry(pos - 1);
		if (prev != NULL) {
			removed = remove_next(prev);
			free(removed);
		}
	}
}
void clear_list() {
	while (is_empty() == 0)
		del(0);
}

void display(FILE* fp) {
	int i = 0;
	Node* p;
	for (p = head; p != NULL; p = p->link, i++) {
		fprintf(stderr, "%3d", i);
		fprintf(fp, "%s", p->data.str);
	}
}
void my_fflush() { while (getchar() != '\n'); }
void main()
{
	char command;
	int pos;
	Line line;
	FILE* fp;

	init_list();
	do {
		printf("[메뉴선택] i-입력, d-삭제, r-변경, p-출력, l-파일일기, s-저장, q-종료 => ");
		command = getchar();
		switch (command) {
		case 'i':
			printf("입력행 번호: ");
			scanf("%d", &pos);
			printf("입력행 내용: ");
			my_fflush();
			fgets(line.str, MAX_CHAR_PER_LINE, stdin);
			insert(pos, line);
			break;
		case 'd':
			printf("삭제행 번호: ");
			scanf("%d", &pos);
			del(pos);
			break;
		case 'r':
			printf("변경행 번호: ");
			scanf("%d", &pos);
			printf("변경행 낸용: ");
			my_fflush();
			fgets(line.str, MAX_CHAR_PER_LINE, stdin);
			replace(pos, line);
			break;
		case 'l':
			fp = fopen("Test.txt", "r");
			if (fp != NULL) {
				while (fgets(line.str, MAX_CHAR_PER_LINE, fp))
					insert(size(), line);
				fclose(fp);
			}
			break;
		case 's':
			fp = fopen("Test.txt", "w");
			if (fp != NULL) {
				display(fp);
				fclose(fp);
			}
		case 'p': display(stdout);
		}
		my_fflush();
	} while (command != 'q');
}