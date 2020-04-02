/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// 翻转
void reverse(struct TreeNode* node){
    // 其实直接node就行，但是我不想做多余的翻转
    if(node && (node -> left || node -> right)){
        struct TreeNode* temp = node -> left;
        node ->left = node -> right;
        node -> right = temp;
    }else
        return;
    reverse(node -> left);
    reverse(node -> right);
}

struct TreeNode* invertTree(struct TreeNode* root){
    //翻转 ----- DFS
    reverse(root);
    return root;
}
