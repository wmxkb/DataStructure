/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool judge(struct TreeNode* lnode, struct TreeNode* rnode){
    // 不同时为空， 说明不对称，返回false
    if(lnode == NULL ^ rnode == NULL){
        return false;
    // 同时为空， 对称， 返回true
    }else if(lnode == NULL){
        return true;
    }
    // 同时不为空， 判定值是否相等且judge2次完成所有镜像的判断
    if(lnode -> val != rnode -> val || !judge(lnode -> left, rnode -> right) || !judge(lnode -> right, rnode -> left))return false;
    // 当前搜索2棵子树镜像对称，返回true
    return true;
}

// 递归方法
bool isSymmetric(struct TreeNode* root){
    // root 为空 ， 直接返回true
    return root ? judge(root -> left, root -> right) : true;
}
