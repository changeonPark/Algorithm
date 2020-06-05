#include <stdio.h>
#define NUMBER 7

int g_arr[] = {7, 1, 9, 5, 3, 4, 1};
int g_tree[4 * NUMBER];

/*구간 합 트리 생성*/
//start: 시작 인덱스, end: 끝 인덱스
int Init(int start, int end, int node){
    if(start == end) return g_tree[node] = g_arr[start];
    int mid = (start + end) / 2;
    //재귀 함수를 통해 두 부분으로 나누고 그 합을 자기 자신으로 한다
    return g_tree[node] = Init(start, mid, node * 2) + Init(mid + 1, end, node * 2 + 1);
}

/*구간 합 계산*/
//left, right: 구간 합을 구하고자 하는 범위
int Sum(int start, int end, int node, int left, int right){
    //범위 밖에 있는 경우
    if(left > end || right < start) return 0;
    //범위 안에 있는 경우
    if(left <= start && right >= end) return g_tree[node];
    //그렇지 않다면 두 부분으로 나누어 합을 구한다.
    int mid = (start + end) / 2;
    return Sum(start, mid, node * 2, left, right) + Sum(mid + 1, end, node * 2 + 1, left, right);
}

/*구간 수정*/
//start: 시작 인덱스, end: 끝 인덱스
//index: 구간 합을 수정하고자 하는 노드
//dif: 수정할 값
void Updata(int start, int end, int node, int index, int dif){
    //범위 밖에 있는 경우
    if(index < start || index > end) return;
    //범위 안에 있으면 내려가며 다르 원소도 갱신
    g_tree[node] += dif;
    if(start == end) return;//한쪽 노드의 리프 노드에 도달했으므로 탈출
    int mid = (start + end) / 2;
    Updata(start, mid, node * 2, index, dif);
    Updata(mid + 1, end, node * 2 + 1, index, dif);
}

void main(){
    //구간 합 트리 생성
    Init(0, NUMBER - 1, 1);
    //구간 합 구하기
    printf("0~6까지의 구간 합: %d\n", Sum(0, NUMBER - 1, 1, 0, 6));
    
    printf("인덱스 3의 원소를 + 2 만큼 수정\n");
    Updata(0, NUMBER - 1, 1, 3, 2);

    printf("수정된 2~6까지의 구간 합: %d\n", Sum(0, NUMBER - 1, 2, 0, 6));
}