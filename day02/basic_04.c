#include <stdio.h>
#define MAX 100 //매크로 상수, MAX는 100dl 담겨있고, 변경할 수 없는 변수
//ArrayList 구조체 저으이
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
    int temp = 0;
    if (index < 0 || list->length == MAX) {
        printf("ERROR: 유효하지 않은 인덱스입니다\n");
        return;
    }
    list->length++;
    for (int i = list->length; i >index; i--) {
        list->ar[i] = list->ar[i-1];
    }
    list->ar[index] = element;

}

/*삭제*/
/*수정*/
/*검색*/
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
    append(&list, 30);
    show(list);

    insert(&list, 0, 40);
    show(list);


    return 0;
}