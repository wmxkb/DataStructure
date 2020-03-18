//导入堆头文件
#include"SqStack.h"
/**
*注意需要修改头文件中栈的元素类型至char
*因为该程序为了简便，修改了StackTraverse的传参
*已在头文件对应地方加上注释
*/
//函数声明
Status LineEdit();
Status Sprint();

int main(){
  //start
  if(LineEdit() == ERROR)
    exit(-1);
  return 0;
}
//打印堆到文件中
Status Sprint(Elemtype* p, FILE* f){
  fprintf(f, "%c", *p);
  return OK;
}
//行编辑函数
Status LineEdit(){
  //声明，初始化栈
  SqStack s;
  InitStack(s);
  //打开文件
  FILE * f = fopen("data.txt","a+");
  if(f == NULL){
    printf("error:1561\n");
    return ERROR;
  }
  char c, e;
  //一层循环 --- 进入行编辑
  while((c = getchar()) != EOF){
    //跳出循环一行结束
    while(c != EOF&& c != '\n'){
      switch(c){
        //退格，出栈
        case '#' :
          Pop(s, e);
          break;
        //退行(删除此行@之前所有内容)，清栈
        case '@' :
          ClearStack(s);
          break;
        //入栈
        default:
          Push(s, c);
      }
      c = getchar();
    }
    //遍历栈，打印入文件
    StackTraverse(s, Sprint, f);
    fclose(f);
    f = fopen("data.txt","a+");
    //非空行->换行
    if(!StackEmpty(s)) fprintf(f, "\n");
    //清空栈
    ClearStack(s);
  }
  //销毁栈
  DestroyStack(s);
  //关闭并保存文件
  fclose(f);
  return OK;
}
