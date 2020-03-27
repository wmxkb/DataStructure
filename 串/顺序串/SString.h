#include<stdio.h>
#include<stdlib.h>

// 状态定义
#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OVERLOW -1 

// 用户可在255以内定义最大串长
#define MAXSTRLEN 255

// 0号单元存放串的长度
typedef unsigned char SString[MAXSTRLEN + 1];

// 状态
typedef int Status;

Status StrAssign(SString T,char *chars){
    int i;  
    if(strlen(chars)>MAX_STR_LEN){
	printf("error: too large\n");  
        return ERROR;
    }else{  
        T[0]=strlen(chars);  
        for(i=1;i<=T[0];i++)  
            T[i]=*(chars+i-1);  
        return OK;  
    }  
}
