#include<stdio.h>
#include<stdlib.h>

// qsort--cmp
int cmp(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}

int main(){
	int weight[20] = {0};
	// 长度， 路径和
	int len = 0, sum = 0, n;
	// 输入叶子节点数
	scanf("%d", &n);
	// 输入叶子节点
	while(len < n && scanf("%d", weight + len++));
	// 计算非叶节点权重和
	for(int i = 0; i < len - 1; ++i){
		qsort(weight + i, len - i, sizeof(int), cmp);
		weight[i + 1] += weight[i];
		sum += weight[i + 1];
	}
	// 输出
	printf("%d", sum);
	return 0;
}
