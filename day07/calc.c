#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cstack.h" //사용자가 정의한 헤더파일을 사용할 경우에는 ""를 사용한다.

//calc(): 후위표현식을 계산하는 함수
int calc(char* post) {
    int length = strlen(post);
    char res;
    Stack s;
    init(&s);

    for (int i = 0; i < length; i++) {
        char ch = post[i];
        if (ch >= '0' && ch <= '9') { // 연산자라면
            push(&s, ch); // 스택에 푸시한다
        }
        else { // 연산자라면
        // 스택에 있는 숫자 두개를 꺼내서 연산한 후에 그 결과를 스택에 넣어준다
            char num1, num2;
            pop(&s, &num2);
            pop(&s, &num1);
            num2 -= '0';
            num1 -= '0';
            switch (ch) {
            case '-':
                res = num1 - num2;
                break;
            case '+':
                res = num1 + num2;
                break;
            case '/':
                res = num1 / num2;
                break;
            case '*':
                res = num1 * num2;
                break;
            }
            res += '0';
            push(&s, res);
        }
    }
    // for문이 다 끝나면 stack에는 계산 결과가 남아있다.

    pop(&s, &res);
    return res-'0';
}

// 연산자의 우선순위를 알려주는 함수
int prec(char op) {
    switch (op) {
    case '+':
    case '-':
        return 0;
    case '*':
    case '/':
        return 1;
    }
    return -1;
}

//중위 표현식을 후위표현식을 바꿔주는 함수
char* inToPost(char exp[]) { // exp: 사용자가 입력한 중위표현식
    // res : 후위표현식으로 바꾼 결과를 저장할 배열
    char* res = (char*)malloc(sizeof(char) * 100);
    int idx = 0; // res의 인덱스 번호
    int length = strlen(exp); // 사용자가 입력한 중위표현식
    char top; // 스택의 top에 들어있는 요소를 담아줄 변수
    Stack s;
    init(&s);

    for (int i = 0; i < length; i++) {
        char ch = exp[i];// ch : 중위표현식 속 문자 하나
        if (ch >= '0' && ch <= '9') {//숫자라면
            res[idx++] = ch; // 그대로 res에 담아준다
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            peek(&s, &top);
            while (!isEmpty(&s) && prec(ch) <= prec(top)) {
                // 스택이 비어있지 않고,
                // 지금 넣고자 하는 연산자(ch)가 스택에 존재하는 연산자(top)보다 우선순위가 작거나 같다면
                pop(&s, &top); // 스택에 있는 연산자를 꺼내서
                res[idx++] = top; // res에 담아주고,
                peek(&s, &top); // 스택에 존재하는 다음 연산자를 top에 담아준다.
            }
            push(&s, ch);// 자신보다 낮은 연산순위가 아래에 쌓인다
        }
        else if (ch == '(') {// 여는 소괄호라면
            // 무조건 스택에 푸시한다
            push(&s, ch);
        }
        else if (ch == ')') { // 닫는 소괄호라면
            //top이 '('가 될때까지 뽑아서 res에 붙여준다
            pop(&s, &top);
            while (top != '(')  {
                res[idx++] = top;
                pop(&s, &top);
            }
        }
    }
    //for문이 다 끝나면 스택에 남아있는 연산자를 res에 붙여준다
    while (!isEmpty(&s)) {
        pop(&s, &top);
        res[idx++] = top;
    }
    res[idx] = '\0';
    return res;
}
int main() {
    // 사용자에게 수식을 입력 받아서
    // 해당 수식에 알맞은 결과를 보여준다
    // 3+7*2
    // 17
    printf("수식입력 : ");
    char exp[100];// 입력받은 중위표현식을 저장해줄 변수
    scanf("%s", exp);
    char* res = inToPost(exp);
    printf("후위표현식으로 바뀐 식 : %s\n", res);

    printf("계산 결과 : %d\n", calc(res));
    return 0;
}
