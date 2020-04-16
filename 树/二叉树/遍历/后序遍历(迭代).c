// 后序遍历的迭代解法
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    // 为序列分配空间
    int* res = (int*)malloc(sizeof(int) * 100);
    // 遍历序列长度
    *returnSize = 0;
    // 空树直接返回
    if(root == NULL) return res;
    // 分配栈空间
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100);
    // 栈顶指针
    int top = 0;
    // 根节点入栈
    stack[0] = root;

    // 迭代 top == -1 是遍历结束，退出
    while(top != -1){
        // 保存当前栈顶指针
        int now = top;
        // 右节点入栈 、 左节点入栈
        if(stack[now] -> right != NULL) stack[++top] = stack[now] -> right;
        if(stack[now] -> left != NULL) stack[++top] = stack[now] -> left;
        //遍历到叶
        if(stack[top] -> left == NULL && stack[top] -> right == NULL){
            // 加入序列，栈顶元素弹出
            res[(*returnSize)++] = stack[top--] -> val;
            // 栈顶指针 != -1 且 栈顶节点已经访问过（即访问过它的子节点） 即加入序列后继续弹出
            // 这里表现为已弹出的节点 == 栈顶节点的子节点
            while(top != -1 && (stack[top] -> left == stack[top + 1] || stack[top] -> right == stack[top + 1])){
                res[(*returnSize)++] = stack[top--] -> val;
            }
        }
    }
    // 释放
    free(stack);
    // 返回
    return res;

}
