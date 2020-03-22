#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int n;
	scanf("%d", &n);
	int Qlen = n;
	//通过数组模拟队列和栈
	int* Q = (int*)malloc(sizeof(int)*n);
	int* S = (int*)malloc(sizeof(int)*n);
	//在队尾插入元素
	for(int i = 0 ; i < Qlen ; ++i){
		scanf("%d", Q + i);
	}
	//从队头弹出元素并入栈
	for(int i = 0; i < Qlen ; ++i){
		S[i] = Q[i];
	}
	
	//栈元素后进先出
	for(int i = n - 1 ; i >= 0 ; --i){
		printf("%d ", S[i]);
	}
	return 0;
}