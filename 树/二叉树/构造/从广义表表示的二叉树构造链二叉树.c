//根据广义表创建二叉树
TreeNode * CreateTree(char *s) {
    TreeNode *root = NULL, *currNode = NULL;
    // 栈
    TreeNode* stack[50];
    // 栈顶指针
    int top = -1;
    // 标记左右
    int flag = 0;
    int index = 0;
    char c = s[index];
    while (c != '\0') {
        switch (c) {
            case '(':
                stack[++top] = currNode;
                // 左括号后为左孩子
                flag = 1;
                break;
            case ',':
                // 逗号后为右孩子
                flag = 0;
                break;
            case ')':
                top--;
                break;
            case ' ':
                break;
            default:
                currNode = (TreeNode *) malloc(sizeof(TreeNode));
                currNode->data = c;
                currNode->right = currNode->left = NULL;
                if (root == NULL) {
                    root = currNode;
                } else {
                    if(flag) stack[top]->right = currNode;
                    else stack[top]->left = currNode;
                    break;
                }
        }
        c = s[++index];
    }
    // 释放
    free(stack);
    return root;
}
