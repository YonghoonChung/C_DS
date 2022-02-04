#include <stdio.h>
#include <stdlib.h>

typedef struct PhysicalCheck {
	int num;
	int age;
	char name[30];
	double height;
	double weight;
}Physic;

typedef struct Node {
	struct Node* llink;//prev
	struct Node* rlink;//next
	Physic data;
}Node;

typedef struct DoublyLinkedList {
	struct Node* head;
	struct Node* tail;
}Dlist;

void init(Dlist* list) {
	list->head = (Node*)malloc(sizeof(Node));
	list->tail = (Node*)malloc(sizeof(Node));

	list->head->rlink = list->tail;
	list->tail->llink = list->head;

	list->head->llink = list->head;
	list->tail->rlink = list->tail;

}
void show(Dlist* list) {
	Node* curr = list->head;
	while (curr->rlink != list->tail) {
		curr = curr->rlink;
		printf("%d 정보\n", curr->data.num);
		printf("이름 : %s\n", curr->data.name);
		printf("나이 : %d살\n", curr->data.age);
		printf("키 : %0.2lfcm\n", curr->data.height);
		printf("몸무게 : %0.2lfkg\n", curr->data.weight);
	}
}
/*추가*/
//맨 뒤에 추가
void append(Dlist* list, Physic element) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;
	newNode->rlink = list->tail;
	list->tail->llink->rlink = newNode;
	newNode->llink = list->tail->llink;
	list->tail->llink = newNode;
}
/*삭제*/
/*수정*/
/*검색*/


int main() {
	Dlist list;
	init(&list);
	Physic p1 = { 1, 10, "Kim", 190.5, 60.7 };
	append(&list, p1);
	show(&list);
	return 0;
}