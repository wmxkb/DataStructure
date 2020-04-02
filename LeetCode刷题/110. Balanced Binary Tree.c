/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// dfs 记录 l r深度 比较后返回
int judge(struct TreeNode* root){
    // 访问到叶子，返回1
    if(!root) return 1;
    // 左子树深度 ， 右子树深度
    int l, r;
    // 分别搜索左右子树 不是高度平衡二叉树， 返回 -1 否则返回子树高度
    return ((l = judge(root -> left)) == -1
            || (r = judge(root -> right)) == -1
            || l - r > 1 || l - r < -1
           )
            ? -1 : 1 + (l > r ? l : r);

}


bool isBalanced(struct TreeNode* root){
    return judge(root) != -1;
}
