#include<stdio.h>
#include "SqStack.h"
#define N 20

//输出栈元素
Status print(Elemtype* p){
  printf("%d ", *p);
  return OK;
}

//求a数组元素所有组合
void combine(SqStack &s, int a[], int start, int n, int m){
  int e; //无用
  //循环取出元素(广度上的搜索),需要搜索 start ~ n - m
  for(int i = start; i <= n - m; ++i){
    //把第一个元素入栈
    Push(s, a[i]);
    //如果需要组合需要的元素 > 1 ， 递归深度 + 1 ，继续取出元素
    if (m > 1)
      combine(s, a, i + 1, n, m - 1);
    //如果在这个深度已经取完所有的元素，遍历栈，输出
    else{
      StackTraverse(s, print);
      printf("\n");
      //弹出栈顶，在当前深度继续搜索
      Pop(s, e);
    }
  }
  //弹出栈顶元素（上一深度所选元素），返回上一深度，继续广度上的搜索
  Pop(s, e);
  return;
}



int main(){
  //存储正整数的数组
  int a[N];
  for(int i = 0 ; i < N ; ++i)a[i] = i + 1;
  int m, k;
  scanf("%d %d", &m, &k);
  //定义栈空间
  SqStack s;
  InitStack(s);
  //生成组合
  combine(s, a, 0, m, k);

  return 0;
}
