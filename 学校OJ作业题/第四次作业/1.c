#include<stdio.h>
#include<stdlib.h>

// 树节点
typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;
// 插入
TreeNode* Insert(TreeNode* node, int val){
	if(node == NULL){
		node = (TreeNode*)malloc(sizeof(TreeNode));
		node -> left = node -> right = NULL;
		node -> val = val;
		return node;
	}
	if(val < node -> val){
		node -> left = Insert(node -> left, val);
	}else{
		node -> right = Insert(node -> right, val);
	}
	return node;
}
// 中序遍历
void print(TreeNode* node){
	if(node -> left != NULL){
		print(node -> left);
	}
	// 输出
	printf("%d ", node -> val);
	if(node -> right != NULL){
		print(node -> right);
	}
}

int main(){
	int n, data;
	TreeNode* tree = NULL;
	// 输入个数
	scanf("%d", &n);
	// 输入
	for(int i = 0; i < n; ++i){
		scanf("%d", &data);
		tree = Insert(tree, data);
	}

	// 遍历
	print(tree);
	return 0;
}
