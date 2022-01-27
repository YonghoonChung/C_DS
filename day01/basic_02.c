#include <stdio.h>

void change(int* ptr) {
	//printf("change() 내부 num 주소 : %d\n", &num);
	//num = 1000;
	*ptr = 1000;
}

int main() {
	int num = 10;
	int* ptr = &num;

	printf("change() 외부 num 주소 : %d\n", &num);
	printf("change() 사용 전 num : %d\n", num);
	change(&num);
	printf("change() 사용 후 num : %d\n", num);

	printf("num : %d\n", num);
	printf("&num : %d\n", &num);
	printf("ptr : %d\n", ptr);
	printf("*ptr : %d\n", *ptr);

	*ptr = 100;
	printf("num : %d\n", num);

	return 0;
}