/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


// 递归 & 分治
struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
	// numsSize == 0, 返回空节点
	if(!numsSize) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int maxnum = 0;
    // 找到区间内最大值位置
    for(int i = 0; i < numsSize; ++i)
        if(nums[i] > nums[maxnum]) maxnum = i;
    // 存储当前最大值
    root -> val = nums[maxnum];
    // 分治 && 递归
    root -> left = constructMaximumBinaryTree(nums, maxnum);
    root -> right = constructMaximumBinaryTree(nums + maxnum + 1, numsSize - maxnum - 1);
    return root;
}
