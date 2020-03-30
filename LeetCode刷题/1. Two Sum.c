/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 排序qsort的比较函数
int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}
//双指针解法，相比于暴力求解降低了时间复杂度
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    int *nums2 = (int*)malloc(sizeof(int)*numsSize);
    int *result = (int*)malloc(sizeof(int)*2);
    // 保存原数组
    for(int i = 0; i < numsSize ; ++i){
        nums2[i] = nums[i];
    }
    // 排序
    qsort(nums, numsSize,sizeof(int),cmp);
    // 双指针解法
    int i = 0, j = numsSize - 1;
    while(nums[i] + nums[j] != target){
        if(nums[i] + nums[j] < target)++i;
        if(nums[i] + nums[j] > target)--j;
    }
    int flag = 1;
    // 和原数组对比查找
    for(int k = 0 ; k < numsSize ; ++k){
        if(flag && nums[i] == nums2[k]){
            result[0] = k;
            flag = 0;
        }
        if(nums[j] == nums2[k]){
            result[1] = k;
        }
    }
    *returnSize = 2;
    return result;
}
