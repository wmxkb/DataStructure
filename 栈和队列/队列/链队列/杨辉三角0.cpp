#include "LinkQueue.h"

void PascalTriangle(int n){
  LinkQueue q;
  InitQueue(q);
  // 一开始入队第一行元素
  EnQueue(q, 1);
  // cnt用于计行数
  int cnt = 0, cnt1 = 0;
  // temp用于保存上一次弹出的数据，初始为 0
  int temp = 0;
  while(cnt < n){
    for(int p = 0 ; p < n - cnt - 1 ; ++p)
      printf("  ");
    // 当前行队列非空，遍历输出同时构造下一行队列
    while(cnt1 <= cnt){
      int e;
      // 队头出队
      DeQueue(q, e);
      // 构造下一行
      EnQueue(q, e + temp);
      // 输出
      printf("%4d", e);
      // 更新左值
      temp = e;
      ++cnt1;
    }
    cnt1 = 0;
    // 行末特殊处理
    EnQueue(q, temp + 0);
    printf("\n");
    // 行首+左结合元素为0
    temp = 0;
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
