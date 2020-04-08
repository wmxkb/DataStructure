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
// 从右到左 root - right - left 次序遍历
void travel(struct TreeNode* root,int depth, int* returnSize, int* res){
    if(root == NULL) return;
    // 每层最右节点看得见，存入res，更新*returnSize
    if(depth > *returnSize){
        res[*returnSize] = root -> val;
        *returnSize = depth;
    }
    // 遍历 右、左子树
    travel(root -> right, depth + 1, returnSize, res);
    travel(root -> left, depth + 1, returnSize, res);
}

int* rightSideView(struct TreeNode* root, int* returnSize){
    // 初始返回数组大小为0
    *returnSize = 0;
    int* res = (int*)malloc(sizeof(int) * 1000);
    // 初始深度应为1
    travel(root, 1, returnSize, res);
    return res;
}
