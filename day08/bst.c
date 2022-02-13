#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* left; // 왼쪽자식을 저장할 포인터변수
	struct Node* right; // 오른쪽자식을 저장할 포인터변수
}BinNode;

// 확인용 함수
// 전위 순회
void proShow(BinNode* node) {
	if (node != NULL) {
		printf("[%d] ", node->data);
		proShow(node->left);
		proShow(node->right);
	}
}
// 중위 순회
void inShow(BinNode* node) {
	if (node != NULL) {
		inShow(node->left);
		printf("[%d] ", node->data);
		inShow(node->right);
	}
}
// 후위 순회
void postShow(BinNode* node) {
	if (node != NULL) {
		postShow(node->left);
		postShow(node->right);
		printf("[%d] ", node->data);
	}
}
// 추가
BinNode* add(BinNode* tree, int element){
	if (tree == NULL) { // 비어있는 트리라면
		// 추가하고자 하는 노드가 root가 된다
		tree = (BinNode*)malloc(sizeof(BinNode));
		tree->data = element;
		tree->left = NULL;
		tree->right = NULL;
	}
	else if (tree->data == element) { // 값이 중복된다면
		printf("ERROR : 중복값 입력 불가\n");
	}
	else if (tree->data < element) {
		tree->right = add(tree->right, element);
	}
	else if (tree->data > element) {
		tree->left = add(tree->left, element);
	}
	return tree;
}

int main() {
	BinNode* root;
	root = NULL;
	root = add(root, 10);
	add(root, 5);
	add(root, 7);
	add(root, 15);
	add(root, 13);
	// add(root, 4);

	proShow(root);
	printf("\n---------------\n");
	inShow(root);
	printf("\n---------------\n");
	postShow(root);

	return 0;
}