#include <stdio.h>
#include <stdbool.h>
#define MAX 100 //매크로 상수, MAX는 100이 담겨있고, 변경할 수 없는 변수
//ArrayList 구조체 저으이

struct Student {
    char name[30];
    int age;
    int score;
};
typedef struct {
    int ar[MAX];// 실질적으로 데이터가 저장되는 저장공간
    int length; // 리스트의 길이를 관리할 변수
}ArrayList;

//리스트 요소 확인용 show()함수
void show(ArrayList list) {
    for (int i = 0; i < list.length; i++) {
        printf("[%d]", list.ar[i]);
    }
    printf("\n");

}

/*추가*/
// 맨뒤에 추가
void append(ArrayList* list, int element) {
    // 이미 가득 차 있다면 실패
    if (list->length == MAX) {
        printf("ERROR: 리스트 가득참\n");
        return;
    }

    //여기까지 왔다면 리스트가 아직 가득 차지 않았다는 의미
    list->ar[list->length] = element;
    list->length++;

}
// 중간에 삽입
// insert(어떤리스트에?, 어떤 위치에?, 어떤 요소를?)
//실패조건 인덱스번호 유효한지, 리스트가 가득 차잇는지
void insert(ArrayList* list, int index, int element) {
    if (index < 0 || index > list->length) {
        printf("ERROR: 유효하지 않은 인덱스입니다\n");
        return;
    }
    if (list->length == MAX) {
        printf("ERROR: 용량 초과됨\n");
        return;
    }
    list->length++;
    for (int i = list->length; i > index; i--) {
        list->ar[i] = list->ar[i - 1];
    }
    list->ar[index] = element;

}

/*삭제*/
// 인덱스 번호로 삭제
void removeByIdx(ArrayList* list, int idx){
    if (idx < 0 || idx > list->length - 1) {
        printf("ERROR: 인덱스번호 잘못됨\n");
        return;
    }
    for (int i = idx; i < list->length-1; i++) { // 범위를 벋어나지 않게 하기위해서 이렇게 만든다
        list->ar[i] = list->ar[i + 1];
    }
    list->length--;
}

// 요소로 삭제
int removeElement(ArrayList* list, int element) {
    // 들어온 숫자의 존재를 파악해야한다
    int idx = 0;
    bool flag = false;
    for (int i = 0; i < list->length; i++){
        if (list->ar[i]==element) {
            idx = i;
            flag = true;
            break;
        }
    }
    //for문이 끝나면 idx에는 삭제할 요소의 인덱스가 들어있다.
    if (flag) {
        removeByIdx(list, idx);
        return 1;
    }
    else {
        //printf("ERROR: 요소가 존재하지 않음");
        return 0;
    }
}

// 중복되는 모든 요소 지우기
void removeElements(ArrayList* list,int element) {
    while(removeElement(list, element));
}

//리스트의 모든 요소 삭제
void clear(ArrayList* list) {
    list->length = 0; // 기존의 값을 모두 쓰레기 값으로 만든다.
}

/*수정*/
// update by index
void update(ArrayList* list, int idx, int element) {
    if (idx < 0 || idx>list->length - 1) {
        printf("ERROR: 잘목된 인덱스");
        return;
    }
    list->ar[idx] = element;
}
/*검색*/
// searching by list's index
void select(ArrayList* list, int idx,int* res) {
    if (idx < 0 || idx> list->length - 1) {
        printf("ERROR: 인덱스 번호 잘못됨\n");
        *res = NULL;
        return;
    }
    *res = list->ar[idx];
}
//list 초기화 함수
void init(ArrayList* list) {
    list->length = 0;
}

int main() {
    ArrayList list;
    init(&list);
    show(list);
    append(&list, 10);
    show(list);
    append(&list, 20);
    show(list);

    insert(&list, 2, 40);
    show(list);

    removeByIdx(&list, 3);
    show(list);

    removeElement(&list, 20);
    show(list);

    clear(&list);
    show(list);
    
    append(&list, 10);
    append(&list, 20);
    append(&list, 20);
    append(&list, 20);
    append(&list, 30);
    show(list);

    removeElements(&list, 20);
    show(list);

    update(&list, 1, 100);
    show(list);
    
    int num;
    select(&list, 0, &num);
    printf("0번째방 요소 : %d\n", num);
    return 0;
}