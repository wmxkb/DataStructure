#include<stdio.h>
#include<stdlib.h>
//最大队列长度
#define MAXQSIZE 100
//定义状态
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define True 1
#define False 0
typedef int QElemtype;
typedef int Status;

typedef struct{
  // 初始化空间基址
  QElemtype *base;
  // 队头指针
  int front;
  // 队尾指针
  int rear;
}SqQueue;

// 初始化队列
Status InitQueue(SqQueue& Q){
  Q.base = (QElemtype*)malloc(sizeof(QElemtype) * MAXQSIZE);
  if(!Q.base){
    printf("error: InitSqQueue fail\n");
    return OVERFLOW;
  }
  // 初始队列队头队尾指向base
  Q.front = Q.rear = 0;
  return OK;
}


// 销毁队列
Status DestroyQueue(SqQueue& Q){
  free(Q.base);
  Q.base = NULL;
  return OK;
}

// 清空队列
Status ClearQueue(SqQueue& Q){
  Q.front = Q.rear = 0;
  return OK;
}

// 判断是否为空
Status QueueEmpty(SqQueue& Q){
  return Q.front == Q.rear ? True : False;
}

// 获取队列长度
int QueueLength(SqQueue Q){
  // 循环队列Q.rear - Q.front可能为负
  return ((Q.rear - Q.front + MAXQSIZE) % MAXQSIZE);
}

// 获得队头元素
Status GetHead(SqQueue Q, QElemtype& e){
  // 非空则返回队头元素
  if(Q.rear != Q.front){
    e = Q.base[Q.front];
    return OK;
  }
  printf("error: SqQueue is Empty\n");
  return ERROR;
}

// 队尾插入元素
Status EnQueue(SqQueue& Q, QElemtype e){
  //对列满
  if((Q.rear + 1) % MAXQSIZE == Q.front)
    return ERROR;
  // 插入元素
  Q.base[Q.rear] = e;
  //更新队尾
  Q.rear = (Q.rear + 1) % MAXQSIZE;
  return OK;
}

// 删除队头元素
Status DeQueue(SqQueue& Q, QElemtype& e){
  //空对列
  if(Q.front == Q.rear)
    return ERROR;
  // 用e返回队头
  e = Q.base[Q.front];
  // 更新队头
  Q.front = (Q.front + 1) % MAXQSIZE;
  return OK;
}

// 从队头到队尾visit遍历
Status QueueTraverse(SqQueue Q, void (*visit)(QElemtype)){
  //空对列
  if(Q.front == Q.rear)
    return ERROR;

  for(int i = Q.front ;i != Q.rear ; i = (i + 1) % MAXQSIZE){
    visit(Q.base[i]);
  }
  return OK;
}
