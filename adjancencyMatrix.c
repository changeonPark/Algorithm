#include <stdio.h>



void main(){
    
    int arr[50][50] = {0,};//������ ���� 2���� �迭 ����    
    int node, edge;//����, ���� ���� ����

    scanf("%d %d", &node, &edge);//����� ���� ������ �� ����
    //������ ����ŭ �ݺ��Ͽ� ���� ����
    for(int i = 0; i < edge; i++){
        int x, y;//�迭�� ��, ���� ��ġ�� ���� ���� ����
        scanf("%d %d", &x, &y);//�Է¹��� x�� y�� ���� ����Ǵ� ��������
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