#include <stdio.h>



void main(){
    
    int arr[50][50] = {0,};//정보를 담을 2차원 배열 선언    
    int node, edge;//정점, 간선 변수 선언

    scanf("%d %d", &node, &edge);//노드의 수와 간선의 수 받음
    //간선의 수만큼 반복하여 정보 저장
    for(int i = 0; i < edge; i++){
        int x, y;//배열의 행, 열의 위치를 담을 변수 선언
        scanf("%d %d", &x, &y);//입력받은 x와 y는 서로 연결되는 정점들임
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    for(int i = 0; i < node; i++){
        for(int j = 0; j < node; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }


}