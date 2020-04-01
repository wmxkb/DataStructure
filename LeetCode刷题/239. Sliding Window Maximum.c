/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//题目要求在线性时间复杂度内解决问题 O(kn)。。。所以穷举不是好方法
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    //返回数组大小为 numsSize - k + 1
    *returnSize = numsSize - k + 1;
    // malloc 数组保存返回值
    int *resultWindow = (int*)malloc(sizeof(int) * (numsSize - k + 1));
    // 队列
    int *queue = (int*)malloc(sizeof(int) * numsSize);
    int front, rear;
    front = rear = 0;
    // 模拟双端队列
    int i = 0;
    while(i < numsSize) {
        // 队尾元素 < 未入队元素 ， 弹出队尾元素
        while (front != rear && nums[queue[rear - 1]] < nums[i]) --rear;
        // 新元素入队
        queue[rear++] = i;
        // 开始滑动窗口
        if(i >= k - 1){
            // 当前窗口最大值加入结果
            resultWindow[i - k + 1] = nums[queue[front]];
            // 队头元素出窗(出队)
            if(front != rear && queue[front] <= i - k + 1) ++front;
        }
        ++i;
    }
    free(queue);
    return resultWindow;
}
