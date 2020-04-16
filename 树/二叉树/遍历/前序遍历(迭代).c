//先序遍历 -- 迭代
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int* res = (int*)malloc(sizeof(int) * 1000), top = 0;
    // 使用栈存储节点
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1000);
    *returnSize = 0;
    if(root == NULL) return NULL;
    // 栈底压入root
    stack[top++] = root;
    while(top != 0){
        // 获取栈顶节点
        root = stack[--top];
        // 存储
        res[(*returnSize)++] = root->val;
        // 右节点先压入栈
        if(root-> right) stack[top++] = root->right;
        // 左节点入栈，优先级 > 右节点
        if(root-> left) stack[top++] = root->left;
    }
    // 释放资源
    free(stack);
    return res;
}
