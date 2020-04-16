#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

// 先序构造二叉树
struct TreeNode* Create(struct TreeNode* root){
	int val;
	// 输入节点值
	scanf("%d", &val);
	// 如果val == -1 返回NULL
	if(val == -1) return NULL;
	root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root -> val = val;
	root -> left = Create(root -> left);
	root -> right = Create(root -> right);
	return root;
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
	struct TreeNode* root;
	root = Create(root);
	Travel(root);

	return 0;
}
