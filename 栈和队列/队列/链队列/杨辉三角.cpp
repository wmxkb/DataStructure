#include "LinkQueue.h"

void PascalTriangle(int n){
  LinkQueue q[2];
  InitQueue(q[0]), InitQueue(q[1]);
  // 一开始入队第一行元素
  EnQueue(q[0], 1);
  // cnt用于计行数
  int cnt = 0;
  // temp用于保存上一次弹出的数据，初始为 0
  int temp = 0;
  // 控制两队列交替使用
  int i = 0, j = 1;
  while(cnt < n){
    for(int p = 0 ; p < n - cnt - 1 ; ++p)
      printf("  ");
    // 当前行队列非空，遍历输出同时构造下一行队列
    while(!QueueEmpty(q[i])){
      int e;
      // 队头出队
      DeQueue(q[i], e);
      // 构造下一行
      EnQueue(q[j], e + temp);
      // 输出
      printf("%4d", e);
      // 更新左值
      temp = e;
    }
    // 行末特殊处理
    EnQueue(q[j], temp + 0);
    printf("\n");
    //ClearQueue(q[i]);
    // 行首+左结合元素为0
    temp = 0;
    // 交换队列编号
    i = i ^ j , j = i ^ j , i = i ^ j;
    ++cnt;
  }
}

int main(){
  // 输入
  int n;
  scanf("%d", &n);
  // begin
  PascalTriangle(n);
  return 0;
}
