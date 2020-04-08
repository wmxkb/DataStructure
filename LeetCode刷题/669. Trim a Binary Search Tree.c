/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// 修剪二叉搜索树
struct TreeNode* trimBST(struct TreeNode* root, int L, int R){
    if(root == NULL) return NULL;
    // 更新左子树
    root -> left = trimBST(root -> left, L, R);
    // 更新右子树
    root -> right = trimBST(root -> right, L, R);
    // 更新根节点
    if(root -> val < L) return root -> right;
    else if(root -> val > R) return root -> left;
    else return root;
}
