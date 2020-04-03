/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// dfs 记录 l r深度
int search(struct TreeNode* root, int* max){
    // 访问到叶子，返回0
    if(!root) return 0;
    // 左子树深度 ， 右子树深度
    int l, r;
    // 分别搜索左右子树
    l = search(root -> left, max);
    r = search(root -> right, max);
    // 更新最大值
    *max = (l + r > *max) ? l + r : *max;
    // 返回子树高度
    return 1 + (l > r ? l : r);
}

// 计算直径
int diameterOfBinaryTree(struct TreeNode* root){
    int max = 0;
    search(root, &max);
    return max;
}
