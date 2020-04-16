// 中序遍历 --- 递归
void inorder(struct TreeNode* root, int* res, int* returnSize){
    if(root == NULL) return;
    inorder(root -> left, res, returnSize);
    // 存入节点值并更新*returnSize
    *(res + (*returnSize)++) = root -> val;
    inorder(root -> right, res, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* res = (int*)malloc(sizeof(int) * 100);
    // *returnSize初始值为0
    *returnSize = 0;
    inorder(root, res, returnSize);
    return res;
}
