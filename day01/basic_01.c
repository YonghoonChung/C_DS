#include <stdio.h>

int main() {
    // �迭
    // �迭�� ����
    // �ڷ��� �迭��[] = {��, ��, ��,,...};
    int ar[] = { 10, 20, 30 };
    printf("ar : %p\n", ar);
    printf("ar + 1 : %p\n", ar + 1);
    printf("ar + 2 : %p\n", ar + 2);

    // * ������
    // 5 * 2 : ���� ������
    // * �ּҰ�: ������ ������. �ش� �ּҷ� ���� ���� �о���
    *ar = 100; // �� �ּ� �ȿ��ٰ� ��������
    printf("*ar : %d\n", *ar);
    printf("*ar+1 : %d\n", *ar+1); // �� �ּҿ� ����� ��
    printf("*ar+2 : %d\n", *ar+2);
    printf("*ar+1 : %d\n", *(ar+1));
    printf("*ar+2 : %d\n", *(ar+2));

    printf("ar[0]: %d\n", ar[0]);
    printf("ar[1]: %d\n", ar[1]);

    
    printf("sizeof(ar) : %zd\n", sizeof(ar));
    printf("sizeof(ar) : %zd\n", sizeof(int));
 

    // ����Ÿ���� �迭
    printf("-----------------------\n");

    char str[] = { 'a','p','p','l','e','\0'};
    printf("sizeof(str) : %zd\n", sizeof(str));
    printf("str : %s\n", str);
    char str2[] = "apple";
    printf("sizeof(str2) : %zd\n", sizeof(str2));
    printf("str2 : %s\n", str2);

    str2[0] = 'K';
    printf("str2[0] : %c\n", str2[0]);

    return 0;
}