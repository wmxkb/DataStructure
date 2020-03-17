#include<stdio.h>
#include"list.h"
//顺序结构线性表前一篇已经给出
//https://www.jianshu.com/p/cf7642e48a4e
#define EXITSUCESS 0
#define FAIL 1
//union --A = A U B
bool equal(ADT a, ADT b) {
    return a == b ? true : false;
}

void print(ADT i) {
    printf("%d ", i);
}

void scan(List &l) {
    int e = 0;
    for (int i = 1;; ++i) {
        scanf_s("%d", &e);
        ListInsert(l, i, e);
        if (getchar() == '\n')break;
    }
}

void Union(List& A, List B) {
    int len_a = ListLength(A);
    for (int i = 1; i <= ListLength(B); ++i) {
        ADT e;
        GetElem(B, i, e);
        if (!LocateElem(A, e, equal)) {
            ListInsert(A, ++len_a, e);
        }
    }
}


int main() {
    List A, B;
    InitList(A);
    InitList(B);
    printf("输入线性表，元素以空格分隔，回车结束\n");
    printf("表A: ");
    scan(A);
    printf("表B: ");
    scan(B);

    Union(A, B);
    printf("表A(A = A U B): ");
    ListTraverse(A, print);
    return EXITSUCESS ;
}
