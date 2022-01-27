#include <stdio.h>

int main() {
	int ar[] = { 1,2,3 };
	printf("ar : %d\n", ar);

	int num = 0;
	int num2 = 100;

	int* ptr = &num;
	printf("ptr : %d\n", ptr);
	ptr = &num2; // 포인터벼누는 주소를 알고 있으며, 다른 주소값을 대입할 수 있따.
	printf("ptr : %d\n", ptr);

	// ar = &num; 배열은 주소를 알고있긴 하지만, 다른 주소값을 대입할 수는 없다.
	ptr = ar;
	printf("ptr : %d\n", ptr);
	printf("ptr : %d\n", *(ptr + 3));

	printf("--포인터형식의 문자열 선언--\n");

	char str[] = "apple";
	//str[] = "japanasdf"; 배열은 변경불가능하다

	char* str2 = "korea";
	str2 = "japanasdf";
	//str[0] = "K";
	printf("str2 : %s\n", str2);

	return 0;
}