#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 10

// 개방주소법을 통한 충돌회피, ClosedHash
typedef struct {
	int st_num;
	char name[30];
}Student;

typedef struct Bucket {
	Student data;
	int status; // -1 : 삭제됨, 0 : 미등록, 1 : 등록
}Bucket;

typedef struct ClosedHash {
	Bucket table[SIZE];
}Hash;

void show(Hash h) {
	printf("----Hash Table----\n");
	for (int i = 0; i < SIZE; i++){
		printf("%d 버킷 : ", i);
		if (h.table[i].status == 1) {
			printf("[%d,%s]\n", h.table[i].data.st_num, h.table[i].data.name);
		}
		else if (h.table[i].status == 0) {
			printf("----미등록----\n");
		}
		else {
			printf("----삭제됨----\n");
		}
	}
}
// 초기화 함수
void init(Hash* h) {
	for (int i = 0; i < SIZE; i++) {
		// 모든 버킷의 상태를 미등록으로 바꿔준다
		h->table[i].status = 0;
	}
}
int hash(int key) {
	return key % SIZE;
}

int rehash(int hv) {// 해시값에 요소가 차있을 경우 다음 해시값을 return하는 재해시함수
	return (hv + 1) % 10;
}

void add(Hash* h, Student s) {
	// 데이터가 저장될 위치 (해시값) 구하기
	int hv = hash(s.st_num);
	Bucket* b = &h->table[hv];
	for (int i = 0; b->status != 0 && i < SIZE; i++) {
		if (b->status == 1 && b->data.st_num == s.st_num) {
			printf("이미 등록된 KEY존재\n");
			return;
		}
		hv = rehash(hv);
		b = &h->table[hv];
	}
	//for문 바깥으로 왔다면 비어잇는 버킷을 찾은것이다.
	b->data = s;
	b->status = 1;
}
//삭제
void removeByKey(Hash* h, int key) {
	int hv = hash(key);
	Bucket* b = &h->table[hv];
	for (int i = 0; b->status != 0 && i < SIZE; i++) {
		if (b->status == 1 && b->data.st_num == key) {
			b->status = -1;
			return;
		}
		hv = rehash(hv);
		b = &h->table[hv];
	}
	printf("해당 키값 존재하지 않음\n");
}
//select()
void select(Hash* h, int key, Student* res) {
	int hv = hash(key);
	Bucket b = h->table[hv];
	for (int i = 0; b.status != 0 && i < SIZE; i++) {
		if (b.data.st_num == key) {
			*res = b.data;
			return;
		}
		hv = rehash(hv);
		b = h->table[hv];
	}
	printf("해당 key 존재하지 않음\n");
}

// 수정
void update(Hash* h, int key, char* name) {
	int hv = hash(key);
	Bucket* b = &h->table[hv];
	for (int i = 0; b->status != 0 && i < SIZE; i++){
		if (b->status == 1 && b->data.st_num == key) {
			strcpy(b->data.name, name);
			return;
		}
		hv = rehash(hv);
		b = &h->table[hv];
	}
	printf("해당 key 존재하지 않음\n");
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

	removeByKey(&h, 15);
	show(h);
	Student res;
	select(&h, 25, &res);
	printf("찾은 학번 %d, 이름 : %s\n", res.st_num, res.name);
	update(&h, 22, "정용빈");
	show(h);


	return 0;
}