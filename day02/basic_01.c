#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 구조체 변수 선언
struct Student{
    char name[30]; //멤버변수
    int kor; //멤버변수
    int eng; //멤버변수
};

//구조체 별명 설정
//구조체 변수 선언시
//struct Korean 구조체변수명;
//Kor 구조체변수명;
typedef struct Korean{
    int age;
}Kor;

typedef struct{
    int age;
} Person;

int main(){
    //변수 선언
    int num;
    // 구조체 변수 선언
    struct Student kim;// kim: 구조체 변수
    // 구조체 내부의 변수(멤버변수)에 값을 저장하기
    // 하위연산자(.)를 활용한다
    kim.eng = 100;
    kim.kor = 70;
    //kim.name = "정용훈"; 
    strcoy(kim.name, "정용훈");
    //문자열 값을 대입하는 함수 strcpy(), string.h에 정의 되어있다


    // char str[20] = "korea";
    // str = "Japan";

    printf("이름:%s\n국어점수: %d\n 수학점수: %d\n",kim.name, kim.kor,kim.eng);

    //변수 선언과 초기화 동시에
    int num1 = 10;
    // 구조체 변수 선언과 초기화 동시에
    struct Student s1 = {"김철수",50,30};;
    printf("이름:%s\n국어점수: %d\n 수학점수: %d\n",kim.name, kim.kor,kim.eng);

    //멤버변수 이름을 직접 면시하여 초기화를 할 수 있다.
    struct Student s2 ={.eng=100, .name="메롱",.kor=70};
    printf("이름:%s\n국어점수: %d\n 수학점수: %d\n",kim.name, kim.kor,kim.eng);

    printf("구조체변수 사이즈 : %d", sizeof(s2));

    //별명 설정한 구조체 변수 선언
    struct Korean k1;
    Kor k2;

    // 별명만 설정한 구조체변수 선언
    Person p1;
    struct Person p2;

    return 0;
}