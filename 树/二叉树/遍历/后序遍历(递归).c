// 前序遍历 --- 递归
void postorder(struct TreeNode* root, int* res, int* returnSize){
    if(root == NULL) return;
    postorder(root -> left, res, returnSize);
    postorder(root -> right, res, returnSize);
    // 存入节点值并更新*returnSize
    *(res + (*returnSize)++) = root -> val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int* res = (int*)malloc(sizeof(int) * 100);
    // *returnSize初始值为0
    *returnSize = 0;
    postorder(root, res, returnSize);
    return res;
}
