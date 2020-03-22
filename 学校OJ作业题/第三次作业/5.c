#include<stdio.h>
#define True 1
#define False 0;
#include<string.h>
typedef int Status;

char OP[7] = {'+', '-', '*', '/', '(', ')','#'};
char getcharwithoutspace();
char Precede(char a, char b);
Status In(char c, char* OP);

int main(){
	//数组模拟栈
	int stack[100];
	//栈顶位置
	int top = 0;
	//栈底压入#
	stack[0] = '#';
	char c;
	while((c = getcharwithoutspace()) != '#'){
		//读取到非运算符直接输出
		if(!In(c, OP)){
			printf("%c", c);
		}else{
			switch(Precede(stack[top], c)){
				//栈顶元素优先级低，运算符入栈
				case '<':
					stack[++top] = c;
					break;
				//栈顶元素优先级高，输出栈顶元素。注意左右括号匹配后top - 1将左括号出栈
				case '>':
					while(top > 0 && Precede(stack[top], c) == '>')
						printf("%c", stack[top--]);
					if(Precede(stack[top], c) == '=')
						--top;
					else
						stack[++top] = c;
					break;
			}
		}
	}
	//输出最后压入栈的运算符
	while(top > 0){
		printf("%c", stack[top--]);
	}
	return 0;
}

//跳过空格读取字符
char getcharwithoutspace(){
  char c;
  while((c=getchar())==' ');
  return c;
}
//判断c是否在OP中
Status In(char c, char* OP){
  for(unsigned int i = 0 ; i < strlen(OP);  ++i){
    if(*(OP + i) == c) return True;
  }
  return False;
}
//返回优先级情况
char Precede(char a, char b){
    int i = 0,j = 0;
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