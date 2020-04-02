/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* Create(int* nums, int left, int right){
    // left > right 即已经Create到树叶了
    if(left > right) return NULL;
    /**
    *偶选右
    *left > right 即已经Create到树叶了
    if(left == right) return NULL;
    */
    // 新节点
    struct TreeNode* p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    // 中间值下标
    int mid = (left + right) / 2;
    p -> val = nums[mid];
    // 左右节点递归生成
    p -> left = Create(nums, left, mid - 1);
    p -> right = Create(nums, mid + 1, right);
    /**
    *偶选右
    p -> left = Create(nums, left, mid);
    p -> right = Create(nums, mid + 1, right);
    */
    return p;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    // 已经有序了，所以直接二分，递归
    // 偶选左
    return Create(nums, 0, numsSize - 1);
    // 偶选右
    //return Create(nums, 0, numsSize);
}
