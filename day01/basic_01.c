#include <stdio.h>

int main() {
    // 배열
    // 배열의 선언
    // 자료형 배열명[] = {값, 값, 값,,...};
    int ar[] = { 10, 20, 30 };
    printf("ar : %p\n", ar);
    printf("ar + 1 : %p\n", ar + 1);
    printf("ar + 2 : %p\n", ar + 2);

    // * 연산자
    // 5 * 2 : 곱셈 연산자
    // * 주소값: 역참조 연산자. 해당 주소로 가서 값을 읽어줘
    *ar = 100; // 그 주소 안에다가 대입해줘
    printf("*ar : %d\n", *ar);
    printf("*ar+1 : %d\n", *ar+1); // 그 주소에 저장된 값
    printf("*ar+2 : %d\n", *ar+2);
    printf("*ar+1 : %d\n", *(ar+1));
    printf("*ar+2 : %d\n", *(ar+2));

    printf("ar[0]: %d\n", ar[0]);
    printf("ar[1]: %d\n", ar[1]);

    
    printf("sizeof(ar) : %zd\n", sizeof(ar));
    printf("sizeof(ar) : %zd\n", sizeof(int));
 

    // 문자타입의 배열
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