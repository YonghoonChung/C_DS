#include <stdio.h>

int main() {
	int ar[] = { 1,2,3 };
	printf("ar : %d\n", ar);

	int num = 0;
	int num2 = 100;

	int* ptr = &num;
	printf("ptr : %d\n", ptr);
	ptr = &num2; // �����ͺ����� �ּҸ� �˰� ������, �ٸ� �ּҰ��� ������ �� �ֵ�.
	printf("ptr : %d\n", ptr);

	// ar = &num; �迭�� �ּҸ� �˰��ֱ� ������, �ٸ� �ּҰ��� ������ ���� ����.
	ptr = ar;
	printf("ptr : %d\n", ptr);
	printf("ptr : %d\n", *(ptr + 3));

	printf("--������������ ���ڿ� ����--\n");

	char str[] = "apple";
	//str[] = "japanasdf"; �迭�� ����Ұ����ϴ�

	char* str2 = "korea";
	str2 = "japanasdf";
	//str[0] = "K";
	printf("str2 : %s\n", str2);

	return 0;
}