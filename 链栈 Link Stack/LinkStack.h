#include<stdio.h>
#include<stdlib.h>
//定义状态
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define True 1
#define False 0

typedef int Status;
typedef int Elemtype;
//定义节点
typedef struct Node{
  //栈的数据域
  Elemtype data;
  //栈的指针域
  struct Node* next;
}Node, *LinkStackPtr;

//定义链栈
typedef struct LinkStack{
  //栈的top指针
  LinkStackPtr top;
  //栈的长度
  int StackLength;
}LinkStack;

//初始化栈
Status InitStack(LinkStack &S){
  //给新节点分配空间
  S.top = (LinkStackPtr)malloc(sizeof(Node));
  if(!S.top){
    printf("error: InitStack false\n");
    return OVERFLOW;
  }
  //栈底做上标记
  S.top -> next = NULL;
  S.StackLength = 0;
  return OK;
}

//清空栈
Status ClearStack(LinkStack &S){
  LinkStackPtr p = S.top;
  while(S.top -> next){
    S.top = S.top -> next;
    free(p);
    p = S.top;
  }
  S.StackLength = 0;
  return OK;
}

//摧毁栈
Status DestroyStack(LinkStack &S){
  ClearStack(S);
  free(S.top);
  return OK;
}

//获得栈的长度
int StackLength(LinkStack &S){
  return S.StackLength;
}

//判断栈是否非空
Status StackEmpty(LinkStack &S){
  return S.StackLength == 0 ? True : False;
}

//获取栈顶元素
Status GetTop(LinkStack &S, Elemtype &e){
  if(S.top -> next == NULL){
    printf("error: Empty！\n");
    return ERROR;
  }
  e = S.top -> next -> data;
  return OK;
}

//入栈
Status Push(LinkStack &S, Elemtype e){
  //定义新的栈顶
  LinkStackPtr p = (LinkStackPtr)malloc(sizeof(Node));
  if(!p){
    printf("error: Push false\n");
    return OVERFLOW;
  }
  //e入栈
  S.top -> data = e;
  p -> next = S.top;
  //栈顶指针移动
  S.top = p;
  //栈长度更新
  ++S.StackLength;
  return OK;
}

//出栈
Status Pop(LinkStack &S, Elemtype &e){
  if(StackEmpty(S)){
    printf("error: Pop false\n");
    return ERROR;
  }
  LinkStackPtr p = S.top;
  //保存栈顶元素值
  e = S.top -> next -> data;
  //移动栈顶指针
  S.top = S.top -> next;
  //释放空间
  free(p);
  //栈长度更新
  --S.StackLength;
  return OK;
}

//遍历
Status StackTraverse(LinkStack &S, Status (*visit)(Elemtype)){
  LinkStackPtr p = S.top -> next;
  while(p != NULL){
    visit(p -> data);
  }
  printf("\n");
  return OK;
}
