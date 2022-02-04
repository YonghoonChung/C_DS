#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int data; //실질적인 리스트의 요소가 저장될 공간
	struct Node* link; // 아직 typedef가 선언이 안됨
}Node; //Node형 typedef 선언이 완료


typedef struct LinkedList {// head처럼 사용한다
	Node* first; // 첫번째 노드의 주소값을 저장할 포인터 변수
	//int size;
}List;

//초기화 함수
void init(List* list) {
	list->first = NULL;
}

// show method
void show(List* list) {
	// 순회용 포인터
	Node* curr = list->first; // curr에는 첫번째 노드를 담아준다.
	while (curr != NULL) {
		printf("[%d]->", curr->data);
		curr = curr->link;
	}
	printf("\n");
}
/* 추가 */
// 맨앞에 추가
void insertFirst(List* list, int element) {
	//새롭게 추가할 노드는 이 함수 호출이 끝나더라도 메모리에 남아있어야 한다.
	// 따라서 힙메모리에 동적할당을 해준다.
	Node* newNode = (Node*)malloc(sizeof(Node));
	// newNode에는 새롭게 만들어진 노드가 할당된 주소가 담겨있다.
	newNode->data = element;
	newNode->link = list->first;
	list->first = newNode; // LinkedList의 list
	//printf("%d노드의 주소 : %d\n", element, newNode);
}

// 맨마지막에 추가
void append(List* list, int element) {
	//리스트의 요소가 한개도 없다면
	if (list->first == NULL) {
		insertFirst(list, element);
		return;
	}
	Node* curr = list->first;
	while (curr->link != NULL) {
		curr = curr->link;
	}// 반복문을 다 돌고 나면 curr에는 마지막 노드가 담긴다.
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;
	newNode->link = NULL;
	curr->link = newNode;
}

void insert(List* list, int idx, int element) {
	// 인덱스번호가 음수이거나 길이보다 클 경우
	if (idx<0 || idx > len(list)) {
		printf("ERROR: 인덱스번호 범위 오류\n");
			return;
	}
	// 삽입하고자 하는 idx가 0번일 경우
	if (idx == 0) {
		insertFirst(list, element);
		return;
	}

	Node* curr = list->first;
	for (int i = 0; i < idx-1; i++) {
		curr = curr->link;
	}
	// 반복문을 다 돌고 curr에는 내가 삽입할 이전 노드가 들어있다.
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;
	newNode->link = curr->link;
	curr->link = newNode;

}

// 리스트 요소의 갯수를 알려주는 함수
int len(List* list) {
	if (list->first == NULL) {
		return 0;
	}
	Node* curr = list->first;
	int length = 0;
	while (curr != NULL) {
		length++;
		curr = curr->link;
	}
	return length;
}

/*삭제*/
//맨 앞 요소 삭제
void removeFirst(List* list) {
	// 리스트가 비어있다면 삭제 실패
	if (list->first == NULL) {
		printf("NO ELEMENTS\n");
		return;
	}
	//삭제할 노드
	Node* removeNode = list->first;
	//첫번째 노드로 삭제할 노드 다음 노드를 담아준다
	list->first = removeNode->link;
	//연결을 끊어준 노드를 메모리에서 해제시켜준다
	free(removeNode);
}

void removeLast(List* list) {
	if (list->first == NULL) {
		printf("NO ELEMENT\n");
		return;
	}
	//리스트의 요소가 한개가 들어있을 경우
	if (len(list) == 1) {
		removeFirst(list);
		return;
	}
	Node* curr = list->first;
	while (curr->link->link != NULL) {// 리스트 요소가 한개 들어있을 경우
		//조건식을 검사하면서 curr -> link가 NULL이기 때문에
		// curr->link->link는 사실상 NULL->link를 써버리는 것과 같게 된다
		//따라서 오류가 발생한다.

		curr = curr->link;
	}
	free(curr->link);
	curr->link = NULL;
}
// 전체 요소 삭제
void clear(List* list) {
	int length = len(list);
	for (int i = 0; i < len(list); i++){
		removeFirst(list);
	}
}
//인덱스 번호로 삭제하기
void removeByIdx(List* list, int idx) {
	if (list->first == NULL){
		printf("NO ELEMENT\n");
		return;
	}
	if (idx <0 || idx > len(list)-1) { // 항상 그 안에있는 숫자로 해야한다.
		printf("ERROR: 인덱스번호 범위 오류\n");
		return;
	}
	if (idx == 0) {
		removeFirst(list);
		return;
	}
	Node* curr = list->first;
	for (int i = 0; i < idx-1; i++){
		curr = curr->link;
	}
	//curr에는 삭제하기 이전노드가 들어가있다.
	Node* removeNode = curr->link;
	curr->link = removeNode->link;

	free(removeNode);
}
/*수정*/
void updateFirst(List* list, int element) {
	//요소사 없을 경우 실패
	if (list->first == NULL) {
		printf("NO ELEMENT\n");
		return;
	}

	list->first->data = element;
}
//인덱스번호로 요소 수정하기
void update(List* list, int idx, int element) {
	//인덱스 범위 오류
	if (idx < 0 || idx>len(list)-1) {
		printf("인덱스 범위 오류\n");
		return;
	}
	Node* curr = list->first;
	for (int i = 0; i < idx; i++){
		curr = curr->link;
	}
	curr->data = element;
}

/*검색*/
void select(List* list, int idx, int* res) {
	if (idx < 0 || idx > len(list) - 1) {
		printf("ERROR: 인덱스 오류\n");
		*res = NULL;
		return;
	}
	Node* curr = list->first;
	for (int i = 0; i < idx; i++){
		curr = curr->link;
	}
	*res = curr->data;
}
int main() {
	List list;
	init(&list);
	insertFirst(&list, 10);
	insertFirst(&list, 200);
	insertFirst(&list, 3000);
	show(&list);

	insert(&list, 0, 1000);
	show(&list);
	
	insert(&list, 2, 1030);
	show(&list);

	append(&list, 1000000);
	show(&list);

	removeFirst(&list);
	removeLast(&list);
	show(&list);

	int res;
	select(&list, 0, &res);
	printf("res : %d\n", res);
	return 0;
}