//顺序结构线性表前一篇已经给出
//https://www.jianshu.com/p/cf7642e48a4e
#include<stdio.h>
#include"list.h"
#define EXITSUCESS 0
#define FAIL 1



void print(ADT i) {
    printf("%d ", i);
}

void scan(List &l, int n) {
    int e = 0;
    for (int i = 1;i <= n; ++i) {
        scanf("%d", &e);
        ListInsert(l, i, e);
    }
}

void reserve(List &l){
    for(int i = 1 , j = ListLength(l) ; i < j;++i,--j){
        int e = 0;
        ListDelete(l, j, e);
        int temp;
        ListInsert(l, i, e);
        ListDelete(l, i + 1, temp);
        ListInsert(l, j, temp);
    }

}


int main() {
    List A;
    int n;

    scanf("%d", &n);
    if(n == 0)printf("Empty");
    InitList(A);
    scan(A, n);
    reserve(A);
    ListTraverse(A, print);
    return EXITSUCESS ;
}
