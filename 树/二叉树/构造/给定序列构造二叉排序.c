// 插入
TreeNode* Insert(TreeNode* node, int val){
    if(node == NULL){
        node = (TreeNode*)malloc(sizeof(TreeNode));
        node -> left = node -> right = NULL;
        node -> val = val;
        return node;
    }
    if(val < node -> val){
        node -> left = Insert(node -> left, val);
    }else{
        node -> right = Insert(node -> right, val);
    }
    return node;
}
