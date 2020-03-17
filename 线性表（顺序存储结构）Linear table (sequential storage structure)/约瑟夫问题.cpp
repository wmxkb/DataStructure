#include<stdio.h>
#include"list.h"
//顺序结构线性表前一篇已经给出
//https://www.jianshu.com/p/cf7642e48a4e
#define EXITSUCESS 0
#define FAIL 1

//利用线性表解决约瑟夫问题
int main(){
    int N;
    scanf_s("%d",&N);
    List l;
    InitList(l);

    //先给表中元素编号: 1，2......n
    for(int i = 0 ; i < N ; ++i){
        ListInsert(l , i + 1 , i + 1);
    }
    //计数 数到三，删除表中该元素
    int count = 0;
    int i = 1;
    while(true){
        count++;
        //如果计数 > 表实际长度 ， 从1记起
        i = i > ListLength(l) ? 1 : i;
        if(!(count % 3)){
            int e;
            //当表中只剩一个元素,找到答案
            if(ListLength(l) == 1){
                GetElem(l , 1 , e);
                printf("%d",e);
                return EXITSUCESS;
            }
            ListDelete(l, i, e);
            count = 0;
            --i;
        }
        ++i;
    }
}
