#include <stdio.h>

void change(int* ptr) {
	//printf("change() ���� num �ּ� : %d\n", &num);
	//num = 1000;
	*ptr = 1000;
}

int main() {
	int num = 10;
	int* ptr = &num;

	printf("change() �ܺ� num �ּ� : %d\n", &num);
	printf("change() ��� �� num : %d\n", num);
	change(&num);
	printf("change() ��� �� num : %d\n", num);

	printf("num : %d\n", num);
	printf("&num : %d\n", &num);
	printf("ptr : %d\n", ptr);
	printf("*ptr : %d\n", *ptr);

	*ptr = 100;
	printf("num : %d\n", num);

	return 0;
}