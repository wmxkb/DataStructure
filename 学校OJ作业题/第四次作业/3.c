#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// 读取序列
void TravelToString(char* s1, char* s2){
	char c;
	// flag用于记录中序后序分界
	int flag = 1, i = 0;
	// max存储序列长度，用于结束读取
	int max = -1;
	while(i != max){
		scanf("%c", &c);
		// 读取完中序序列
		if(c == ' ') {
			flag = 0;
			// 串尾标记
			s1[i] = '\0';
			max = i;
			// 更新i
			i = 0;
			continue;
		}
		// 存储
		if(flag){
			s1[i++] = c;
		}else{
			s2[i++] = c;
		}
	}
	// 串尾标记
	s2[i] = '\0';
}
// 分治策略
void PrintPreorder(char* s1, int len1, char* s2, int len2){
	if(len1 == 0) return;
	// 获取根节点
	char root = s2[len2 - 1];
	printf("%c", root);
	// 寻找根节点在中序遍历中的位置
	int index = -1;
	while(s1[++index] != root);
	// 继续划分左右子树
	PrintPreorder(s1, index, s2, index);
	PrintPreorder(s1 + index + 1, len1 - index - 1, s2 + index, len1 - index - 1);
}
int main(){

	char s1[20], s2[20];
	int len1, len2;
	// 读取 中序遍历、后序遍历序列
	TravelToString(s1, s2);
	len1 = strlen(s1);
	len2 = strlen(s2);

	// 分治
	PrintPreorder(s1, len1, s2, len2);

	return 0;
}
