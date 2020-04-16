// 前序遍历 --- 递归
void preorder(struct TreeNode* root, int* res, int* returnSize){
    if(root == NULL) return;
    // 存入节点值并更新*returnSize
    *(res + (*returnSize)++) = root -> val;
    preorder(root -> left, res, returnSize);
    preorder(root -> right, res, returnSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int* res = (int*)malloc(sizeof(int) * 100);
    // *returnSize初始值为0
    *returnSize = 0;
    preorder(root, res, returnSize);
    return res;
}
