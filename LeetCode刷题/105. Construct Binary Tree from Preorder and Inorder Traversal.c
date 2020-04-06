/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// 递归 & 分治
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    // 因为前序、中序的长度相等，其中一个为0时返回NULL即可
    if(preorderSize == 0) return NULL;
    // 创建当前子树根节点
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    // 前序遍历的第一个节点就是根节点
    root -> val = preorder[0];
    // 找到中序遍历中根节点的位置，根节点左侧是左子树，故leftlength是左子树长度
    int leftlength = -1;
    while(inorder[++leftlength] != preorder[0]);
    // 更新前序、中序遍历数组范围，继续生成当前根节点下左右子树
    root -> left = buildTree(preorder + 1, leftlength, inorder, leftlength);
    root -> right = buildTree(preorder + 1 + leftlength, preorderSize - leftlength - 1, inorder + leftlength + 1, inorderSize - leftlength - 1);
    // 返回根节点
    return root;
}
