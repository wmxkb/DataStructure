struct TreeNode* Create(struct TreeNode** nodes, int n){
    // nodes存储的是叶节点
    int i = 0;
    while(i < n - 1){
        // 更新森林并排序
        sortnodes(i, n, nodes);
        // 新节点
        struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        // 相加
        temp -> val = nodes[i] -> val + nodes[i + 1] -> val;
        temp -> left = nodes[i]; temp -> right = nodes[i + 1];
        // 新的权值节点加入
        nodes[i + 1] = temp;
        ++i;
    }
    return nodes[i];
}
