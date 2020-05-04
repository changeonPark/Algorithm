#include <stdio.h>

void point(int buf){
    int num = 3;
    buf = num;

}

void point2(int *buf){
    int num = 3;
    *buf = num;
}


void main(){
    int number = 5;
    point(number);
    printf("%d\n", number);
    point2(&number);
    printf("%d\n", number);
}