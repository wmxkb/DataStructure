/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/*
// 最小化递归问题
void MinTri(struct TreeNode* root, struct TreeNode** now_r){
    // 遍历到树叶返回
    if(root == NULL) return;
    // 后序遍历？？
    // 不对， 是先遍历右子树的后序遍历
    MinTri(root -> right, now_r);
    MinTri(root -> left, now_r);
    // 更新右节点
    root -> right = *now_r;
    // 左节点置空
    root -> left = NULL;
    // 返回上一层前保存当前节点
    *now_r = root;
}
// 二叉树展开为链表
void flatten(struct TreeNode* root){
    // 记录节点，同时也是当前父节点的右子节点
    struct TreeNode* now_r = NULL;
    // flatten
    MinTri(root, &now_r);
}

*/

// 尝试迭代解法
void flatten(struct TreeNode* root){
    // last为左子树最右节点
    struct TreeNode* p = root, * last;
    while(p != NULL){
        // 如果p节点有左子树， 取下来接右边去...
        if(p -> left){
            last = p -> left;
            while(last -> right) last = last -> right;
            last -> right = p -> right;
            p -> right = p -> left;
            p -> left = NULL;
        }
        // 右移
        p = p -> right;
    }
}
