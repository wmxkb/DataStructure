/*
// 动态规划 时间复杂度O(n*n)，空间复杂度O(n)
int numTrees(int n){
    int* nums = (int*)malloc(sizeof(int) * (n + 1));
    memset(nums, 0, sizeof(int) * (n + 1));
    nums[0] = nums[1] = 1;

    for(int i = 2; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            nums[i] += nums[j - 1] * nums[i - j];
        }
    }
    return nums[n];
}
*/

// 数学方法 时间复杂度O(n) 空间复杂度O(1)
// 卡塔兰数 nums[n] = nums[n - 1] * 2*(2n + 1) / (n + 2)
int numTrees(int n){
    // 乘法过程会溢出，所以先使用long存储
    long num = 1;
    // 一层循环
    for(int i = 0; i < n; ++i){
        num = num * 2 * (2 * i + 1) / (i + 2);
    }
    return (int)num;
}
