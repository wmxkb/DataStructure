#include<stdio.h>
#include<stdlib.h>
#define INITSIZE 100
#define INCREASEMENT 20
//本题使用数组操作模拟栈操作
int main(){
	//初始化长度
	int size; 
	size = INITSIZE;
	char *stack = (char*)malloc(sizeof(char)*INITSIZE);
	char c;
	int result = 0, len = 0;
	int flag = 1;
	
	while((c = getchar()) != '@'){
		//转折点，存储长度，控制出栈flag
		if(c == '&'){
			result = len;
			flag = 0;
			continue;
		}
		//&前入栈 ，&后出栈
		if(flag){
			stack[len++] = c;
			if(len + 1 == size){
				stack = (char*)realloc(stack, sizeof(char)*(size + INCREASEMENT));
				size += INCREASEMENT;
			}
		}else{
			//不匹配输出no
			if(stack[--len] != c){
				printf("no\n");
				//释放空间
				free(stack);
				return 0;
			}
		}
	}
	//若能执行到这一步，说明是镜像，输出长度
	printf("%d\n", result);
	//释放空间
	free(stack);
	return 0;
}