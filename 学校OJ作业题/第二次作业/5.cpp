#include<stdio.h>
#include"list.h"
//顺序结构线性表前一篇已经给出
//https://www.jianshu.com/p/cf7642e48a4e
void print(ADT i) {
    printf("%d ", i);
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    List l;
    InitList(l);
    int i = 0;
    for(i = 0; i < n ; ++i){
        int e;
        scanf("%d", &e);
        ListInsert(l, i + 1, e);
    }
    int count = 0;
    for(i = 0; i < n-count ; ++i){
        int e;
        GetElem(l, i + 1, e);
        if(e == k){
            ListDelete(l, i + 1, e);
            --i;
            ++count;
        }
    }

    ListTraverse(l,print);

    return 0;
}
