#include<stdio.h>
#include<stdlib.h>

//定义状态
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define True 1
#define False 0
typedef int QElemtype;
typedef int Status;

// 链队列节点
typedef struct QNode{
  // 数据域
  QElemtype data;
  // 指针域
  struct QNode *next;
}QNode, *QueuePtr;

// 链队列
typedef struct{
  // 队头指针
  QueuePtr front;
  // 队尾指针
  QueuePtr rear;
}LinkQueue;

// 构造空队列
Status InitQueue(LinkQueue &Q){
  Q.rear = Q.front = (QueuePtr)malloc(sizeof(QNode));
  if(!Q.rear){
    printf("error: InitQueue fail\n");
    return OVERFLOW;
  }
  Q.rear -> next = NULL;
  return OK;
}

// 销毁队列
Status DestroyQueue(LinkQueue &Q){
  QueuePtr p = Q.front, t;
  while(p){
    t = p -> next;
    free(p);
    p = t;
  }
  Q.front = Q.rear = NULL;
  return OK;
}

// 将Q清为空队列
Status ClearQueue(LinkQueue &Q){
  QueuePtr p = Q.front -> next, t;
  Q.front -> next = NULL;
  while(p){
    t = p -> next;
    free(p);
    p = t;
  }
  Q.rear = Q.front;
  return OK;
}
// 判断队列是否为空
Status QueueEmpty(LinkQueue Q){
  if(Q.front == Q.rear){
    return True;
  }
  return False;
}

// 返回队列长度
int QueueLength(LinkQueue Q){
  QueuePtr p = Q.front;
  int count = 0;
  while(p != Q.rear){
    ++count;
    p = p -> next;
  }
  return count;
}

// 返回队头元素
Status GetHead(LinkQueue Q, QElemtype &e){
  if(Q.front == Q.rear){
    printf("error:queue is Empty!\n");
    return ERROR;
  }
  e = Q.front -> data;
  return OK;
}

// 插入元素
Status EnQueue(LinkQueue &Q, QElemtype e){
  Q.rear -> data = e;
  QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
  if(!p) return OVERFLOW;
  p -> next = NULL;
  Q.rear = Q.rear -> next = p;
  return OK;
}
// 删除元素
Status DeQueue(LinkQueue &Q, QElemtype &e){
  if(Q.front == Q.rear){
    printf("error:empty queue!!!\n");
    return ERROR;
  }
  e = Q.front -> data;
  QueuePtr p = Q.front;
  Q.front = Q.front -> next;
  free(p);
  return OK;
}

// 遍历
Status QueueTraverse(LinkQueue Q, void (*visit)(QElemtype)){
  QueuePtr p = Q.front;
  while(p != Q.rear){
    visit(p -> data);
    p = p -> next;
  }
  return OK;
}
