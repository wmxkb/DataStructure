#define N 100000
void store(int val, char* res) {
    // 获取res当前长度
    int len = strlen(res);
    // 存储当前值
    char tmp[N] = {0};
    // 工作指针
    int pos = 0;
    while (val > 0) {
        // 按位划分val
        int div = val % 10;
        // 更新写入位置 sprintf() 返回值是成功写入的长度
        pos += sprintf(tmp + pos, "%d", div);
        val = val / 10;
    }
    // 保存长度， 避免重复计算
    int tmplen = strlen(tmp);
    // 写入res串
    for (int i = tmplen - 1; i >= 0; i--) {
        res[len + tmplen - 1 - i] = tmp[i];
    }
    // val间以#分隔
    strcat(res, "#");
    return;
}
// 先序遍历
void preorder(struct TreeNode* root, char* res) {
    if (root == NULL) return;
    // 将val用字符串存储
    store(root -> val, res);
    preorder(root -> left, res);
    preorder(root -> right, res);
    return;
}

// 序列化
char* serialize(struct TreeNode* root) {
    char* res = (char*)calloc(N, sizeof(char));
    // 先序遍历
    preorder(root, res);
    return res;
}

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

// 反序列化
struct TreeNode* deserialize(char* data) {
    // 获取字符串长度
    int len = strlen(data);
    // 初始值设为0 NULL
    int val = 0;
    struct TreeNode* root = NULL;
	int nums[10000];
	int k = 0;
    // 转整型数组
    for (int i = 0; i < len; i++) {
        if (data[i] == '#') {
            nums[k++] = val;
            val = 0;
        }else{
            val = val * 10 + data[i] - '0';
        }
    }
    // 已知长度，定义第二个数组存放排序后数据
	int nums1[k + 1];
	for(int i = 0; i < k; ++i) nums1[i] = nums[i];

    // 冒泡sort
	for(int i = 0; i < k - 1; ++i){
		for(int j = 0; j < k - i - 1; ++j){
            if(nums1[j] > nums1[j + 1]){
                nums1[j] = nums1[j] ^ nums1[j + 1];
                nums1[j + 1] = nums1[j] ^ nums1[j + 1];
                nums1[j] = nums1[j] ^ nums1[j + 1];
            }
        }
    }
	// 通过前序&中序遍历结果生成二叉树
	return buildTree(nums,k,nums1,k);
}
