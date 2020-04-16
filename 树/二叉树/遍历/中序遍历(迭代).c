// 迭代，利用栈存储节点实现中序遍历
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int* travel = (int*)malloc(sizeof(int) * 1000);
    struct TreeNode* node = root, *stack[1000];
    // 根节点入栈底
    stack[0] = root;
    //栈顶指针
    int top = 0;
    while(top != -1){
        // 优先遍历左子树
        if(stack[top] != NULL){
            stack[++top] = stack[top] -> left;
            continue;
        }
        // 遍历右子树
        if(--top != -1){
            travel[(*returnSize)++] = stack[top] -> val;
            // 注意此时舍弃stack[top],因为中序遍历已经遍历过根节点，所以返回上一层遍历右子树
            stack[top] = stack[top] -> right;
        }
    }
    return travel;
}
