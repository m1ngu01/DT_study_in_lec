/*
* 프로그램 내용 : 8.1이진트리를 위한 노드 구조체와 
* 실습일 : 2023.05.24
* 실습자 : 임민규
* 학번 : 202011309
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
typedef char TElement;
typedef struct BinTrNode {
	TElement data;
	struct BinTrNode* left;
	struct BinTrNode* right;
}TNode;
typedef TNode* Element;
TNode* root;

Element data[MAX_QUEUE_SIZE];
int front;
int rear;

void error(const char* str) {
	printf("%s\n", str);
	exit(1);
}

void init_queue() { front = rear = 0; ; }
int is_empty() { return front == rear;; }
int is_full() { return (rear + 1) % MAX_QUEUE_SIZE == front; }
int size() { return (rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }

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


void init_tree() { root = NULL;  }
int is_empty_tree() { return root == NULL; }
TNode* get_root() { return root; }

TNode* create_tree(TElement val, TNode* l, TNode* r) {
	TNode* n = (TNode*)malloc(sizeof(TNode));
	n->data = val;
	n->left = l;
	n->right = r;
	return n;
}

void preorder(TNode* n) {
	if (n != NULL) {
		printf("[%c]", n->data);
		preorder(n->left);
		preorder(n->right);
	}
}

void inorder(TNode* n) {
	if (n != NULL) {
		
		preorder(n->left);
		printf("[%c]", n->data);
		preorder(n->right);
	}
}

void postorder(TNode* n) {
	if (n != NULL) {

		preorder(n->left);
		preorder(n->right);
		printf("[%c]", n->data);
	}
}

void levelorder(TNode* root) {
	TNode* n;
	if (root == NULL) return;
	init_queue();
	enqueue(root);
	while (!is_empty()) {
		n = dequeue();
		if (n != NULL) {
			printf("[%c] ", n->data);
			enqueue(n->left);
			enqueue(n->right);
		}
	}
}

int count_node(TNode* n) {
	if (n == NULL) return 0;
	return 1 + count_node(n->left) + count_node(n->right);
}

int count_leaf(TNode* n) {
	if (n == NULL) return 0;
	if (n->left == NULL && n->right == NULL) return 1;
	else return count_node(n->left) + count_node(n->right);
}

int calc_height(TNode* n) {
	int hLeft, hRight;
	if (n == NULL) return 0;
	hLeft = calc_height(n->left);
	hRight = calc_height(n->right);
	return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
}

void main() {

	TNode* b, * c, * d, *e, *f;
	init_tree();
	d = create_tree('D', NULL, NULL);
	e = create_tree('E', NULL, NULL);
	b = create_tree('B', d, e);
	f = create_tree('F', NULL, NULL);
	c = create_tree('C', f, NULL);
	root = create_tree('A', b, c);

	printf("\n   In-Order : ");	inorder(root);
	printf("\n  pre-Order : ");	preorder(root);
	printf("\n post-Order : ");	postorder(root);
	printf("\nLevel-Order : "); levelorder(root);
	printf("\n");

	printf("노드의 개수 = %d\n", count_node(root));
	printf("단말의 개수 = %d\n", count_leaf(root));
	printf("트리의 높이 = %d\n", calc_height(root));


}
