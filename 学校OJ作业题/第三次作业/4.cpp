#include"SqStack.h"
void BaseConversion(){
    SqStack s;
    int N;
    InitStack(s);
	begin:
    scanf("%d", &N);
	if(N >= 0){
		if(!N){
			printf("0\n");
			return;
		}
		while(N){
			Push(s, N % 8);
			N /= 8;
		}
		int e = 0;
		while(!StackEmpty(s)){
			Pop(s, e);
			printf("%d", e);
		}
	}else goto begin;
}
int main(){
    BaseConversion();
    return 0;
}
