#include "LinkQueue.h"

void print(QElemtype e){
  printf("%d " , e);
}

int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  LinkQueue q;
  InitQueue(q);
  //赋值（编号）
  for(int i = 1 ; i <= n ; ++i){
    EnQueue(q, i);
  }

  //QueueTraverse(q, print);
  int count = 0, e = 0;
  while(QueueLength(q) > 1){
    //如果数到m，删除队头元素
    if(++count % m == 0){
      DeQueue(q, e);
    //否则将队头元素删除，添加至队尾
    }else{
      DeQueue(q, e);
      EnQueue(q, e);
    }
  }

  GetHead(q, e);
  DestroyQueue(q);
  printf("num: %d\n", e);
  return 0;
}
