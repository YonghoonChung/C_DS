#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

typedef struct {
	int st_num;
	char name[30];
}Student;

typedef struct Node {
	Student data;
	struct Node* link;
}Node;

typedef struct Hash {
	Node* table[SIZE];
}Hash;

void show(Hash h) {
	printf("----Hash Table----\n");
	for (int i = 0; i < SIZE; i++){
		Node* curr = h.table[i];
		printf("%d버킷 : ", i);
		while (curr != NULL) {
			printf("[%d, %s] -> ", curr->data.st_num, curr->data.name);
			curr = curr->link;
		}
		printf("\n");

	}
}
void init(Hash* h) {
	for (int i = 0; i < SIZE; i++) {
		h->table[i] = NULL;
	}
}
int hash(int key) {
	return key % SIZE;
}

void add(Hash* h, Student data) {
	int hv = hash(data.st_num);
	Node* curr = h->table[hv];
	while (curr != NULL) {
		if (curr->data.st_num == data.st_num) {
			printf("중복된 KEY 존재\n");
			return;
		}
		curr = curr->link;
	}
	// 중복된 key가 없다는 의미
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = h->table[hv];
	h->table[hv] = newNode;
}
//삭제
void removeByKey(Hash* h, int key) {
	int hv = hash(key);
	Node* curr = h->table[hv];
	while (curr != NULL) {
		if(curr->data == )
	}
	Node* removeNode = (Node*)
}
//수정
void update(Hash* h, int key, char* name) {
	int hv = hash(key);
	Node* curr = h->table[hv];
}
//검색
void select(Hash* h, int key, Student* res) {
	int hv = hash(key);
	Node* curr = h->table[hv];
}
int main() {
	Hash h;
	init(&h);

	Student s1 = { 15,"김영월" };
	Student s2 = { 22,"김영화" };
	Student s3 = { 25,"김영수" };
	Student s4 = { 17,"김영목" };

	add(&h, s1);
	add(&h, s2);
	add(&h, s3);
	add(&h, s4);

	show(h);
	return 0;
}