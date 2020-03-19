#include "SqStack.h"
#include<string.h>
int EvaluateExpression();

char OP[7] = {'+', '-', '*', '/', '(', ')','#'};
int main(){
  printf("Expression =  %d\n",EvaluateExpression());
  return 0;
}

//判断c是否再OP中
Status In(char c, char* OP){
  for(unsigned int i = 0 ; i < strlen(OP);  ++i){
    if(*(OP + i) == c) return True;
  }
  return False;
}

//返回优先级情况
char Precede(char a, char b){
    int i,j;
    //优先级表
    char pre[][7]={
        {'>','>','<','<','<','>','>'},
        {'>','>','<','<','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'<','<','<','<','<','=',' '},
        {'>','>','>','>',' ','>','>'},
        {'<','<','<','<','<',' ','='}};
    switch(a){
        case '+': i = 0; break;
        case '-': i = 1; break;
        case '*': i = 2; break;
        case '/': i = 3; break;
        case '(': i = 4; break;
        case ')': i = 5; break;
        case '#': i = 6; break;
    }
    switch(b){
        case '+': j = 0; break;
        case '-': j = 1; break;
        case '*': j = 2; break;
        case '/': j = 3; break;
        case '(': j = 4; break;
        case ')': j = 5; break;
        case '#': j = 6; break;
    }
    return pre[i][j];
}

//二元运算
int Operate(int a, char op, int b){
  int result;
  switch(op){
    case '+': result = a + b; break;
    case '-': result = a - b; break;
    case '*': result = a * b; break;
    case '/': result = a / b; break;
  }
  return result;
}

//跳过空格读取字符
char getcharwithoutspace(){
  char c;
  while((c=getchar())==' ');
  return c;
}

int EvaluateExpression(){
  //定义两种类型的栈
  SqStack OPND;
  SqStackChar OPTR;
  InitStack(OPTR);
  InitStack(OPND);
  //'#'作为栈底元素
  Push(OPTR, '#');
  //输入
  char c = getcharwithoutspace();
  //获得栈顶元素
  char e;
  GetTop(OPTR, e);
  //进行运算直至读取到#且栈内无其余操作符后退出
  while((c != '#') || (e != '#')){
    //若不是运算符，则入栈
    if(!In(c, OP)){
	     int n = 0;
	     do{
         //输入的字符 -> 数字
         n = n * 10 + (c - '0');
         c = getcharwithoutspace();
	     }while(!In(c, OP));
       Push(OPND, n);
    }else{
      //如果输入的是运算符，则和栈顶的运算符比较优先级
      GetTop(OPTR, e);
      switch(Precede(e, c)){
        //栈顶元素优先级低
        case '<':
          Push(OPTR, c);
          c = getcharwithoutspace();
          break;
        //脱去括号并接受下一个字符
        case '=':
          Pop(OPTR, e);
          c = getcharwithoutspace();
          break;
        //退栈并将运算结果入栈
        case '>':
          char theta;
          int b, a;
          Pop(OPTR, theta);
          Pop(OPND, b);
          Pop(OPND, a);
          Push(OPND, Operate(a, theta, b));
          break;
        /*test
        default:
          printf("??????");
          break;
        */
      }
    }
    //获取栈顶运算符
    GetTop(OPTR, e);
  }
  int result;
  //获取结果
  GetTop(OPND, result);
  return result;
}
