#include <stdio.h>
#include <string.h>
#define SIZE 10

typedef struct Hash {
	int table[SIZE];//실질적인 해시테이블
}Hash;

// 초기화 함수
void init(Hash* h) {
	for (int i = 0; i < SIZE; i++) {
		h->table[i] = 0;
	}
}
void show(Hash h) {
	printf("-----hash table----\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d : [%d]\n", i, h.table[i]);
	}
}
// 저장될 데이터의 인덱스번호(해시값)를 계산해주는 함수
int hash(int key) {
	return key % SIZE;
}

//데이터 추가하기
void add(Hash* h, int data) {
	int hv = hash(data);//추가하고자 하는 data의 인덱스번호
	h->table[hv] = data;
}

typedef struct StrHash {
	int table[SIZE];
}SHash;

int shash(char* key) {
	int total = 0;
	for (int i = 0; i < strlen(key); i++) {
		total += key[i];
	}
	return total % SIZE;
}
void sadd(SHash* h, char* key, int value) {
	int hv = shash(key);
	h->table[hv] = value;
}
void sshow(SHash h) {
	printf("-----shash table----\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d : [%d]\n", i, h.table[i]);
	}
}
void sinit(SHash* h) {
	for (int i = 0; i < SIZE; i++) {
		h->table[i] = 0;
	}
}

int main() {
	SHash sh;
	sinit(&sh);
	sadd(&sh, "Kim", 20);
	sshow(sh);



	Hash h;
	init(&h);
	show(h);

	add(&h, 2021556);
	show(h);

	add(&h, 2021120);
	show(h);

	return 0;
}