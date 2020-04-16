// 先序构造二叉树
struct TreeNode* Create(struct TreeNode* root){
    int val;
    // 输入节点值
    scanf("%d", &val);
    // 如果val == -1 返回NULL
    if(val == -1) return NULL;
    root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root -> val = val;
    root -> left = Create(root -> left);
    root -> right = Create(root -> right);
    return root;
}
