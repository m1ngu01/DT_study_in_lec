/*
* 프로그램 내용 : 8.1 이진트리를 위한 노드 구조체와 기본 연산들 (트리의 추가 연산 제외)
* 실습일 : 2023.05.24
* 실습자 : 임민규
* 학번 : 202011309
*/
#include <stdio.h>
#include <stdlib.h>

typedef char TElement;
typedef struct BinTrNode {
	TElement data;
	struct BinTrNode* left;
	struct BinTrNode* right;
}TNode;
TNode* root;

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

void main() {

	TNode* b, * c, * d, *e, *f;
	init_tree();
	d = create_tree('D', NULL, NULL);
	e = create_tree('E', NULL, NULL);
	b = create_tree('B', d, e);
	f = create_tree('F', NULL, NULL);
	c = create_tree('C', f, NULL);
	root = create_tree('A', b, c);
}
