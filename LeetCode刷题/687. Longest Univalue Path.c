/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// 递归
int travel(struct TreeNode* root, int* maxresult){
    // 空节点返回0
    if(root == NULL)return 0;
    int l, r;
    // 分别计算左右子树最长同值路径
    l = travel(root -> left, maxresult);
    r = travel(root -> right, maxresult);
    // 计算当前树和左右树的衔接
    l = (root -> left != NULL && root -> left -> val == root -> val) ? l + 1 : 0;
    r = (root -> right != NULL && root -> right -> val == root -> val) ? r + 1 : 0;
    // 历史最大路径与当前树最大路劲比较并更新
    *maxresult = *maxresult > l + r ? *maxresult : l + r;
    // 返回l、r中较大值
    return l > r ? l : r;
}

int longestUnivaluePath(struct TreeNode* root){
    // 存储历史最大值
    int maxresult = 0;
    // 递归
    travel(root, &maxresult);
    return maxresult;
}
