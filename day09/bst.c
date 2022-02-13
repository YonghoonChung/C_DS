#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* left; // 왼쪽자식을 저장할 포인터변수
	struct Node* right; // 오른쪽자식을 저장할 포인터변수
}BinNode;

// 확인용 함수
// 전위 순회
void proShow(BinNode* node);
// 중위 순회
void inShow(BinNode* node);
// 후위 순회
void postShow(BinNode* node);
// 추가
BinNode* add(BinNode* tree, int element);

//삭제
void removeElement(BinNode* root, int element);

// 검색, 반복문
void selectRoop(BinNode* node, int key);
// 검색, 재귀함수

BinNode* select(BinNode* node, int key);

int selectByKey(BinNode* node, int key);

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
	printf("\n");
	removeElement(root, 15);
	inShow(root);
	printf("\n");
	selectRoop(root, 5);
	printf("\n");
	select(root, 5);

	return 0;
}

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
BinNode* add(BinNode* tree, int element) {
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

//삭제
void removeElement(BinNode* root, int element) {
	if (root == NULL) {
		printf("ERROR: 트리비어있음\n");
		return;
	}
	//삭제할 노드 찾기
	BinNode* curr = root;
	BinNode* parent = NULL;
	BinNode* child = NULL;

	while (curr != NULL) {
		if (curr->data < element) {// 현재 노드보다 삭제하고자 하는 요소가 더 크다면
			parent = curr;
			curr = curr->right; // 오른쪽에서 계속 진행
		}
		else if (curr->data > element) {
			parent = curr;
			curr = curr->left;
		}
		else { // 현재 노드와 삭제하고자 하는 노드가 서로같다면
			break;
		}
	}
	// 1. 만일 삭제하고자 하는 노드를 찾지 못했다면 curr은 NULL값이 들어있다
	if (curr == NULL) { // 만일 삭제하고자 하는 노드를 찾지 못했다면
		printf("ERROR: 요소 없음\n"); // 삭제 실패
		return;
	}
	// 2. curr에는 내가 삭제하고자 하는 노드가 들어있다.
	// parent에는 내가 삭제하고자 하는 부모노드가 들어있다.

	// 3. 만일 삭제하고자 하는 노드가 root라면 curr에는 삭제할 노드(root)가,
	// parent에는 NULL값이 들어있다

	// 2. 만일 삭제하고자 하는 노드가 리프노드라면
	if (curr->left == NULL && curr->right == NULL) {//리프노드라면
		if (parent == NULL) { // 리프면서 루트라면
			root = NULL; // 루트를 NULL로
			//free(curr); // 해당노드는 메모리에서 해제
		}
		else { // 리프지만 루트노드는 아닌경우
			if (parent->right == curr) { //parent->data < curr->data) {
				parent->right = NULL;
				// free(curr);
			}
			else { // 삭제할 노드가 부모의 왼쪽자식이라면
				parent->left = NULL;
			}
			//free(curr);
		}
		//free(curr);
	}
	// 3. 만일 삭제하고자 하는 노드가 자식 1개를 갖고 있다면
	else if (curr->left != NULL || curr->right != NULL) {
		if (curr->left != NULL) { // 삭제할 노드가 왼쪽자식을 가진 경우
			child = curr->left;
		}
		else { // 삭제할 노드가 오른쪽 자식을 가진 경우
			child = curr->right;

		}
		if (parent == NULL) { // 자식이 하나인 루트를 삭제하고자 할 경우
			root = child;
		}
		else {
			if (curr == parent->right) { // 부모의 오른쪽 자식이라면
				parent->right = child;
			}
			else {// 왼쪽 자식이라면
				parent->left = child;
			}

		}
	}

	//else if (curr->left == NULL && curr->right != NULL) { // 오른쪽자식만 갖고있다면
	//	if (parent->right == curr) {// 부모의 오른쪽 자식이라면
	//		parent->right = curr->right;
	//	}
	//	else { // 왼쪽 자식이라면
	//		parent->left = curr->right;

	//	}
	//}
	//else if (curr->left != NULL && curr->right == NULL) { // 왼쪽자식만 갖고있다면
	//	if (parent->right == curr) {// 부모의 오른쪽 자식이라면
	//		parent->right = curr->left;
	//	}
	//	else { // 왼쪽 자식이라면
	//		parent->right = curr->left;
	//	}
	//}
	// 4. 만일 삭제하고자 하는 노드가 자식 2개를 갖고 있다면
	else {// 자식 두 개라면
		BinNode* succ_parent = curr;
		BinNode* succ = curr->left;

		// 계승할 노드를 찾아서 succ에 담아준다
		// 1. 왼쪽 서브트리에서 최대값 찾기
		// 2. 오른쪽 서브트리에서 최솟값 찾기
		// 둘중 하나를 선택함
		while (succ->right != NULL) {
			succ_parent = succ;
			succ = succ->right;
		}
		// while문이 끝나면
		// succ에는 계승할 노드가, succ_parent에는 계승할 노드의 부모가 있다.
		// succ에 담긴 값을 curr->data에 옮겨준다
		curr->data = succ->data;
		// 계승할 노드의 부모의 자식을 NULL값으로 바꾸어주고
		succ_parent->right = succ->left; //없으면 어차피 NULL이 들어간다
		curr = succ; // 나중에 메모리에서 해제될 curr에 succ를 넣어준다.
		// 계승할 노드를 메모리에서 해제시켜준다
		/*free(succ);
		return;*/
	}
	free(curr); // 해당노드는 메모리에서 해제
}

// 검색, 반복문
void selectRoop(BinNode* node, int key) {
	if (node == NULL) {
		printf("ERROR: 트리가 비어있음\n");
		return;
	}
	BinNode* curr = node; // 루트부터 시작
	while (curr != NULL) {
		if (key > curr->data) {//찾고자하는 값이 현재노드보다 크다면 
			curr = curr->right; //오른쪽에서 계속 탐색
		}
		else if (key < curr->data) { // 찾고자하는 값이 현재 노드보다 작다면
			curr = curr->left; // 왼쪽에서 계속 탐색
		}
		else {
			break;
		}
	}
	// while문이 종료되었을때 curr에 NULL이 들어있다면 검색 실패
	if (curr == NULL) {
		printf("ERROR : 검색오류\n");
		return;
	}
	// while문이 종료되면 curr에는 내가 찾고자 하는 데이터가 들어있는 노드가 담겨있다.
	printf("찾음 %d\n", curr->data);
}
// 검색, 재귀함수

BinNode* select(BinNode* node, int key) {
	if (node == NULL) {
		return NULL;
	}
	else if (node->data == key) {
		printf("찾기 성공! %d\n", node->data);
		return node;
	}
	else if (key > node->data) {
		node = select(node->right, key);
	}
	else {
		node = select(node->left, key);
	}
}

int selectByKey(BinNode* node, int key) {
	BinNode* res = select(node, key);
	if (res == NULL) {
		printf("찾기 실패\n");
		return -999;
	}
	else {
		return res->data;
	}
}