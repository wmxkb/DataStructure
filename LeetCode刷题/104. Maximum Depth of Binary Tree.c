/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void find(struct TreeNode* node, int *cnt, int *max){
    // 空节点直接返回
    if(node == NULL) return;
    // 该节点非空 计数加一 更新当前深度
    (*cnt)++;
    // 更新最大深度
    if(*cnt > *max){
        *max = *cnt;
    }
    //进入下一层
    find(node -> left, cnt, max);
    find(node -> right, cnt, max);

    // 当前深度搜索完毕，返回上一深度  计数减一
    (*cnt)--;
}

int maxDepth(struct TreeNode* root){
    // cnt记录深度 max记录最大深度
    int cnt, max;
    cnt = max = 0;
    // 遍历树
    find(root, &cnt, &max);
    return max;
}
