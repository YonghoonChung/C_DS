#include<stdio.h>
#include<stdlib.h>

typedef struct PhysicalCheck {
	int num;
	int age;
	char name[30];
	double height;
	double weight;
}Physic;

typedef struct Node {
	struct Node* llink;// prev
	struct Node* rlink;// next
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
		printf("키 : %.2lfcm\n", curr->data.height);
		printf("몸무게 : %.2lfkg\n\n", curr->data.weight);
	}
}

/*추가*/
//맨 뒤에 추가
// 맨 앞에 추가
void insertFirst(Dlist* list, Physic element) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;
	newNode->llink = list->head;
	newNode->rlink = list->head->rlink;
	list->head->rlink->llink = newNode;
	list->head->rlink = newNode; // 먼저 사용하면 못 찾아간다


}
void append(Dlist* list, Physic element) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;
	newNode->rlink = list->tail;
	list->tail->llink->rlink = newNode;
	newNode->llink = list->tail->llink;
	list->tail->llink = newNode;
}
//리스트 길이를 return 하는 함수(요소의 갯수)
int len(Dlist* list) {
	//if (list->head->rlink == list->tail) {
	//	return 0;
	//} // 만약 요소가 0개 라면 length에 들어있는 0이 return 되기 때문에
	// 따로 적어줄 필요는 없다.
	int length = 0;
	Node* curr = list->head;
	while (curr->rlink != list->tail) {
		curr = curr->rlink;
		length++;
	}
	return length;
}

// 인덱스 번호로 추가하기
void insert(Dlist* list, int idx, Physic element) {
	int length = len(list);
	if (idx < 0 || idx>length) {
		printf("ERROR: 인덱스 오류\n");
		return;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = element;
	Node* curr;
	if (idx < length / 2) {
		curr = list->head;
		for (int i = 0; i < idx; i++) {
			curr = curr->rlink;
		}
		// 반복이 끝나면 curr에는 내가 삽입하고자 하는 위치의 앞 노드가 들어있다.
	}
	else {
		curr = list->tail;
		for (int i = length; i > idx; i--) {
			curr = curr->llink;
		}
		curr = curr->llink;
		// 반복이 끝나면 curr에는 내가 삽입하고자 하는 위치의 뒷 노드가 들어잇다
		//newNode->rlink = curr;
		//newNode->llink = curr->llink;
		//curr->llink->rlink = newNode;
		//curr->llink = newNode;
	}
	newNode->rlink = curr->rlink;
	newNode->llink = curr;

	curr->rlink->llink = newNode;
	curr->rlink = newNode;
	// 반복이 끝나면 curr에는 내가 삽입하고자 하는 위치의 앞 노드가 들어있다.
}
/*삭제*/
void removeFirst(Dlist* list) {
	//리스트가 비어있다면 실패
	if (list->head->rlink == list->tail) {
		printf("ERROR: 리스트 비어있음\n");
		return;
	}
	Node* removeNode = list->head->rlink;
	list->head->rlink = removeNode->rlink;
	removeNode->rlink->llink = list->head;
	free(removeNode);
}
void removeLast(Dlist* list) {
	Node* removeNode = list->tail->llink;
	removeNode->llink->rlink = list->tail;
	list->tail->llink = removeNode->llink;
	free(removeNode);
}
void removeByIdx(Dlist* list, int idx) {
	int length = len(list);
	if (idx < 0 || idx> length - 1) {
		printf("ERROR: 인덱스오류\n");
	}
	Node* removeNode;
	if (idx < length / 2) {// 인덱스번호가 앞쪽일 경우
		removeNode = list->head;
		for (int i = 0; i < idx; i++) {
			removeNode = removeNode->rlink;
		}
		// 반복이 끝나면 removeNode에는 삭제할 노드가 들어있다
	}
	else {// 인덱스번호가 뒤쪽일 경우
		removeNode = removeNode = list->tail;
		for (int i = length; i > idx; i--){
			removeNode = removeNode->llink;
		}
		// 반복이 끝나면 removeNode에는 삭제할 노드가 들어있다
	}

	removeNode->llink->rlink = removeNode->rlink;
	removeNode->rlink->llink = removeNode->llink;
	free(removeNode);
}
//회원번호로 삭제
void removeByNum(Dlist* list, int num) {
	/*(내가한거)
	Node* removeNode = list->head;
	while (removeNode != list->tail) {
		if (num == removeNode->data.num) {
			removeNode->llink->rlink = removeNode->rlink;
			removeNode->rlink->llink = removeNode->llink;
			free(removeNode);
			break;
		}
		removeNode = removeNode->rlink;
	}*/
	Node* removeNode = list->head;
	int check = 0;
	while (removeNode->rlink != list->tail) {
		removeNode = removeNode->rlink;
		if (num == removeNode->data.num) {
			check = 1;
			break;
		}
	}
	//만일 if문 안으로 들어가지 않고 while문이 종료되었다면
	//removeNode에는 마지막노드가 들어있게 된다(엉뚱한 노드)
	if (check == 0) {
		printf("ERROR: 해당회원번호 없음\n");
		return;
	}
	// if문 안으로 들어가서 break가 실행되었다면
	// removeNode에는 삭제할 노드가 들어있게 된다
	removeNode->llink->rlink = removeNode->rlink;
	removeNode->rlink->llink = removeNode->llink;
	free(removeNode);

}
/*수정*/
void updateByNum(Dlist* list, int num, Physic element) {
	Node* target = list->head;
	int check = 0;
	while (target->rlink != list->tail) {
		target = target->rlink;
		if (target->data.num == num) {
			target->data = element;
			check = 1;
			return;
		}
	}
	if (check == 0) {
		printf("ERROR: 해당 회원번호 없음\n");
	}

}
// 인덱스번호로 수정
void updateByIdx(Dlist* list, int idx, Physic element) {
	int length = len(list);
	if (idx <0 || idx>length - 1) {
		printf("ERROR:인덱스 오류\n");
		return;
	}
	Node* target = list->head;
	for (int i = 0; i < idx+1; i++){
		target = target->rlink;
	}
	//반복문이 끝나면 target에는 수정하고자 하는 노드가 들어있다.
	target->data = element;

}
/*검색*/
void selectByNum(Dlist* list, int num, Physic* res) {
	Node* target = list->head;
	while (target->rlink != list->tail) {
		target = target->rlink;
		if (target->data.num == num) {
			*res = target->data;
			return;
		}
	}
	printf("ERROR: 해당회원번호 없음");
}

int main() {
	Dlist list;
	init(&list);
	Physic p1 = { 1, 10, "kim", 180.5, 60.7 };
	Physic p2 = { 2, 15, "park", 160.5, 50.7 };
	append(&list, p1);
	append(&list, p2);
	show(&list);
	printf("------\n");
	Physic p3 = { 3, 20,"choi", 150.4, 50.5 };
	insertFirst(&list, p3);
	show(&list);
	printf("------\n");
	Physic p4 = { 4, 25,"lee", 180.4, 70.2 };
	insert(&list, 0, p4);
	show(&list);

	Physic res;
	selectByNum(&list, 1, &res);

	/*printf("%d번\n")*/
	return 0;
}