/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 先序遍历
void preorder(struct TreeNode* root, int** res, int* returnSize){
    if(root == NULL) return;
    // 存入节点值并更新*returnSize
    *(*res + (*returnSize)++) = root -> val;
    preorder(root -> left, res, returnSize);
    preorder(root -> right, res, returnSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int* res = (struct TreeNode*)malloc(sizeof(struct TreeNode) * 1000);
    // *returnSize初始值为0
    *returnSize = 0;
    preorder(root, &res, returnSize);
    return res;
}
