#include"SqStack.h"
void BaseConversion(){
    SqStack s;
    int N;
    InitStack(s);
    scanf("%d", &N);
    while(N){
        Push(s, N % 2);
        N /= 2;
    }
    int e;
    while(!StackEmpty(s)){
        Pop(s, e);
        printf("%d ", e);
    }
}
int main(){
    BaseConversion();
    return 0;
}
