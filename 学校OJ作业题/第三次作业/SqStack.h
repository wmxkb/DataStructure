#include<stdio.h>
#include<stdlib.h>
//初始化时存储空间分配量
#define INIT_SIZE 100
#define INCREMENT_SIZE 10
//定义状态
#define OVERFLOW -1
#define OK 1
#define ERROR 0
#define True 1
#define False 0

//typedef int Elemtype;
typedef char Elemtype;
//定义状态类型
typedef int Status;
//顺序栈结构定义
typedef struct{
    //基址，指向栈底
    Elemtype* base;
    //栈顶指针
    Elemtype* top;
    //栈空间大小（单位:元素）
    int Stacksize;
}SqStack;

//初始化栈（空栈）
Status InitStack(SqStack &S){
    //给栈元素分配初始空间
    S.base = (Elemtype*)malloc(sizeof(Elemtype)*INIT_SIZE);
    //若内存分配失败，返回ERROR
    if(!S.base){
        printf("error: 233内存分配失败\n");
        return OVERFLOW;
    }
    //栈顶指针指向栈底
    S.top = S.base;
    //栈空间大小为初始化给的大小
    S.Stacksize = INIT_SIZE;
    return OK;
}

//摧毁栈
Status DestroyStack(SqStack &S){
    //若栈未初始化，返回ERROR
    if(!S.base){
        printf("error: 栈未初始化\n");
        return ERROR;
    }
    //释放栈内元素空间
    free(S.base);
    //栈顶栈底指针置空
    S.base = S.top = NULL;
    //栈大小归0
    S.Stacksize = 0;
    return OK;
}

//清空栈
Status ClearStack(SqStack &S){
    //若栈未初始化，返回ERROR
    if(!S.base){
        printf("error: 栈未初始化\n");
        return ERROR;
    }
    //使栈顶指向栈底
    S.top = S.base;
    //栈大小归0
    S.Stacksize = 0;
    return OK;
}

//判断S是否为空栈
Status StackEmpty(SqStack &S){
    //若栈未初始化，返回ERROR
    if(!S.base){
        printf("error: 栈未初始化\n");
        return ERROR;
    }
    //若栈底指针 == 栈顶指针 ， 为空栈
    if(S.base == S.top){
        return True;
    }
    return False;
}

//返回栈里元素个数（栈的长度）
int StackLength(SqStack &S){
    //如果栈未初始化，返回0
    if(!S.base) return 0;
    //栈长度 = （栈顶指针 - 栈底指针） / 栈元素大小
    return S.top - S.base ;
}

//返回栈顶元素
Status GetTop(SqStack &S, Elemtype &e){
    //若栈是空栈，返回ERROR
    if(S.top == S.base){
        printf("error: 返回栈顶元素失败\n");
        return ERROR;
    }
    //通过e返回栈顶元素
    e = *(S.top - 1);
    return OK;
}
//压入元素e为新的栈顶元素
Status Push(SqStack &S, Elemtype e){
    if(S.top - S.base >= S.Stacksize){
        S.base = (Elemtype*)realloc(S.base, sizeof(Elemtype)* (S.Stacksize + INCREMENT_SIZE));
        if(!S.base){
            printf("error: 内存分配失败\n");
            return OVERFLOW;
        }
        //若空间不足，重新分配，需要重新定位栈顶指针
        S.top = S.base + S.Stacksize;
        S.Stacksize += INCREMENT_SIZE;
    }
    *S.top++ = e;
    return OK;
}

//弹出栈顶元素， 用e返回其值
Status Pop(SqStack &S, Elemtype &e){
    //若为空栈，返回ERROR
    if(S.base == S.top) return ERROR;
    //移动栈顶指针后通过e保存栈顶元素的值
    e = *--S.top;
    return OK;
}

//遍历栈，调用visit函数
Status StackTraverse(SqStack S, Status(*visit)(Elemtype* /*,FILE* f*//*, int, int*/)/*, FILE* f*//*,int i, int j*/){
    for(Elemtype* p = S.base; p < S.top ; ++p){
        Status s = visit(p/*, f*//*, i, j*/);
        /*
        if(s == 2){
          return 2;
        }
        */
        if(s != OK){
            printf("ERROR: StackTraverse False");
            return ERROR;
        }
    }
    return OK;
}