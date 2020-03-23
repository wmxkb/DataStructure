#include "SqQueue.h"


void print(QElemtype p){
  printf("%d ", p);
}
int main(){
  QElemtype e;
  SqQueue q;
  InitQueue(q);
  for(int i = 0 ; i <= 10 ; ++i)
    EnQueue(q, i);
  DeQueue(q, e);
  QueueTraverse(q, print);
  return 0;
}
