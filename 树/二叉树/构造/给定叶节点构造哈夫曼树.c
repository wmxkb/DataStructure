/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

void sortnodes(int left, int n, struct TreeNode** nodes){
	for(int i = left; i < n - 1; ++i){
		for(int j = i + 1; j < n; ++j){
			if(nodes[j] -> val < nodes[i] -> val){
				struct TreeNode* temp;
				temp = nodes[i];
				nodes[i] = nodes[j];
				nodes[j] = temp;
			}
		}
	}
}
// 层序遍历
void Travel(struct TreeNode* root){
    // 顺序队列，数据较小直接用数组模拟
    struct TreeNode* nodes[100], *temp;
    // 队头 队尾
    int front, rear;
    front = rear = 0;
    // 根节点入栈
    nodes[rear++] = root;
    // 循环结束条件是队空
    while(rear - front != 0){
        // 队尾出队
        temp = nodes[front++];
        // 输出
        printf("%d ", temp -> val);
        // 将出队节点的左右子节点入队
        if(temp -> left) nodes[rear++] = temp -> left;
        if(temp -> right) nodes[rear++] = temp -> right;
    }
}
int main(){
	int i = 0, n;
    scanf("%d", &n);
    struct TreeNode *root, ** nodes = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * n);
	for(int i = 0; i < n; ++i){
		nodes[i] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		nodes[i] -> left = NULL;
		nodes[i] -> right = NULL;
	}

    while(i < n && scanf("%d", &(nodes[i++] -> val)));
		for(int m = 0; m < n; ++m) printf("%d~",nodes[m] -> val);
		printf("\n");
    // 计算非叶节点权重和
	// nodes存储的是叶节点
	int i = 0;
    while(i < n - 1){
		// 更新森林并排序
        sortnodes(i, n, nodes);
		// 新节点
		struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		// 相加
		temp -> val = nodes[i] -> val + nodes[i + 1] -> val;
		temp -> left = nodes[i]; temp -> right = nodes[i + 1];
		// 新的权值节点加入
        nodes[i + 1] = temp;
		++i;
    }
	root = nodes[i];
	Travel(root);
	return 0;
}


*/

struct TreeNode* Create(struct TreeNode** nodes, int n){
    // nodes存储的是叶节点
    int i = 0;
    while(i < n - 1){
        // 更新森林并排序
        sortnodes(i, n, nodes);
        // 新节点
        struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        // 相加
        temp -> val = nodes[i] -> val + nodes[i + 1] -> val;
        temp -> left = nodes[i]; temp -> right = nodes[i + 1];
        // 新的权值节点加入
        nodes[i + 1] = temp;
        ++i;
    }
    return nodes[i];
}
