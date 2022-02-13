#include <stdio.h>

int getSum(int n) {
	int total = 0;
	for (int i = 1; i <= n; i++) {
		total += i;
	}
	return total;
}

int reSum(int n) {
	if (n == 1) return 1;
	return n + reSum(n - 1);
}
//1부터 매개변수로 받아온 값까지의 곱을 알려주는 함수 만들기
// 반복문
// 재쉬함수
int factorial(int n) {
	int res = 1;
	for (int i = 1; i <= n; i++) {
		res *= i;
	}
	return res;
}
int re_fac(int n) {
	if (n == 1) return 1;
	return n * re_fac(n - 1);
}

// 이름을 5번 출력해주는 함수, 재귀함수 
int rePrint(int n) {
	printf("name\n");
	if (--n == 0) return 1;
	return rePrint(n);
}
int main() {
	int n = 10;
	rePrint(n);
	return 0;
}