/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// 合并
struct TreeNode* Merge(struct TreeNode* t1, struct TreeNode* t2){
    // t1 t2 有一个不为空
    if(t1 || t2){
        // 新节点
        struct TreeNode* newp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        // 置空
        newp -> left = newp -> right = NULL;
        // 相加
        newp -> val = (t1 ? t1 -> val : 0) + (t2 ? t2 -> val : 0);
        // 左指针
        newp -> left = Merge(t1 ? t1 -> left : NULL, t2 ? t2 -> left : NULL);
        // 右指针
        newp -> right = Merge(t1 ? t1 -> right : NULL, t2 ? t2 -> right : NULL);
        // 返回合并后当前树
        return newp;
    }else{
        // 都为空返回NULL
        return NULL;
    }
}

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
    // 合并二叉树 ----- 递归
    return Merge(t1, t2);

}
