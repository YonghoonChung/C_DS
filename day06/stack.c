#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Stack {
    int ar[MAX];
    int top;// 꼭대기의 인덱스 번호를 알고있는 변수
}Stack;

void init(Stack* s) {
    s->top = -1; // 요소가 없으므로 현재 꼭대기는 -1이 된다.
}
// 확인하는 함수
void show(Stack* s) {
    printf("------------------\n");
    for (int i = 0; i < s->top + 1; i++) {
        printf("| %d ", s->ar[i]);
    }
    printf("\n------------------\n");
}
//push() : 스택에 요소를 추가하는 함수
void push(Stack* s, int element) {
    //이미 스택에 요소가 가득차 있다면 실패
    if (s->top == MAX - 1) {
        printf("STACK 가득참\n");
        return;
    }
    //s->top++;
    s->ar[++s->top] = element;
}
//pop() : 스택에서 요소를 삭제해주는 함수,삭제된 요소를 return한다.
int pop(Stack* s) {
    // 스택이 비어있을 경우 실패
    if (s->top == -1) {
        printf("스택 비어있음\n");
        return 0;
    }
    // int target = s->ar[s->top];
    //s->top--;
    //return target;

    return s->ar[s->top--];
}
//peek(): top에 위치한 요소를 엿보는 함수
int peek(Stack* s) {
    // 비어있다면 실패
    if (s->top== -1) {
        printf("요소 비어있음\n");
        return 0;
    }
    return s->ar[s->top];
}

//clear()
void clear(Stack* s){
    s->top = -1;
}

int main() {
    Stack s;
    init(&s);

    push(&s, 10);
    show(&s);
    push(&s, 20);
    push(&s, 30);
    show(&s);
    push(&s, 40);
    show(&s);

    clear(&s);
    show(&s);
    pop(&s);
    show(&s);

    printf("top에 있는 요소 : %d\n\n", peek(&s));


    return 0;
}