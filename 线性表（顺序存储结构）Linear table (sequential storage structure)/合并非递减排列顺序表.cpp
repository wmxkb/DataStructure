#include<stdio.h>
//顺序结构线性表前一篇已经给出
//https://www.jianshu.com/p/cf7642e48a4e
#include"list.h"
#define EXITSUCESS 0
#define FAIL 1
//MergeList---合并线性表


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

void MergeList(List A , List B , List &C) {
    //由于C是新线性表，需要进行初始化
    InitList(C);
    int i, j, k;
    i = j = 1;
    k = 0;//还是效率至上，所以单独给k初值0.
    ADT e1, e2;
    while (i <= ListLength(A) || j <= ListLength(B)) {
        //首先取出A,B中的元素e1,e2
        GetElem(A, i, e1);
        GetElem(B, j, e2);
        if (i <= ListLength(A) && j <= ListLength(B)) {//A,B中均还有元素
            if (e1 <= e2) {//由于A、B元素皆为非递减排列，所以不需要全程搜索,算法具有线性时间复杂度。
                ListInsert(C, ++k, e1);
                ++i;
            }
            else {
                ListInsert(C, ++k, e2);
                ++j;
            }
        }
        else if (i <= ListLength(A)) {//仅剩A中有元素
            ListInsert(C, ++k, e1);
            ++i;
        }
        else {//仅剩B中有元素
            ListInsert(C, ++k, e2);
            ++j;
        }
    }
}
int main() {
    List A, B, C;
    InitList(A);
    InitList(B);
    printf("输入线性表A、B , A、B非递减有序排列 ，元素以空格分隔 ，回车结束\n");
    printf("表A: ");
    scan(A);
    printf("表B: ");
    scan(B);
    MergeList(A, B, C);
    printf("表C(合并A、B,且C也为非递减有序排列): \n");
    ListTraverse(C,print);
    return EXITSUCESS;
}
