#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef	int Element;
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
Node* find(Element e) {
	Node* p;
	for (p = head; p != NULL; p = p->link)
		if (p->data == e) return p;
	return NULL;
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

Node* remove_next(Node	*prev)
{
	Node* removed= prev->link;
	if (removed != NULL)
		prev->link= removed->link;
	return removed;
}
void del(int pos){
	Node* prev, *removed;
	if
		(pos ==	0 && is_empty() ==	0)	{
		removed	= head	;
		head= head->link;
		free(removed);

	}
	else
	{
		prev= get_entry	(pos-1);
		if(prev != NULL){
			removed	= remove_next(prev)	;
			free(removed)	;
		}
	}
}
void clear_list() {
	while (is_empty() == 0)
		del(0);
}
void print_list(const char* msg) {
	Node* p;
	printf("%s[%2d]:", msg, size());
	for (p = head; p != NULL; p = p->link)
		printf("%2d ", p->data);
	printf("\n");
}

void main()
{
	init_list();
	insert(0, 10);
	insert(0, 20);
	insert(1, 30);
	insert(size(), 40);
	insert(2, 50);
	print_list("단순연결리스트로 구현한 List(삽입x5)");
	replace(2, 90);
	print_list("단순연결리스트로 구현한 List(교체x1)");
	del(2);
	del(size() - 1);
	del(0);
	print_list("단순연결리스트로 구현한 List(삽입x3)");
	clear_list();
	print_list("단순연결리스트로 구현한 List(정리후)");
}
