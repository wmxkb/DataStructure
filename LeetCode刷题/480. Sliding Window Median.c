/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void sort(double tempWindow[], int k){
    // 冒泡 && 减少交换次数
    // 优先策略不同，这里先对部分有序序列进行冒泡插入
    // 传统冒泡直接和所有无序序列冒泡得到有序序列
    for(int i = 1; i < k; ++i){
        for(int j = i ; j > 0; --j){
            if(tempWindow[j] < tempWindow[j - 1]){
                double temp = tempWindow[j];
                tempWindow[j] = tempWindow[j - 1];
                tempWindow[j - 1] = temp;
            }else
                break;
        }
    }
}

// 先来暴力解法...
double* medianSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    // 返回结果数组大小
    *returnSize = numsSize - k + 1;
    int l, r;
    l = 0; r = k - 1;
    // 结果
    double* result = (double*)malloc(sizeof(double) * (*returnSize));
    // 窗口
    double* tempWindow = (double*)malloc(sizeof(double) * k);
    for(int i = l; i <= r; ++i){
        tempWindow[i - l] = nums[i];
    }
    sort(tempWindow, k);
    // 遍历
    while(r < numsSize){
        // copy window
        // 使用二分查找
        // 尽可能少的改动有序数组
	    if(l != 0){
            int low, high;
            low = 0; high = k - 1;
            while(low <= high){
                int mid = (low + high) / 2;
                if(nums[l - 1] < tempWindow[mid]){
                    high = mid - 1;
                }else if(nums[l - 1] > tempWindow[mid]){
                    low = mid + 1;
                }else{
                    tempWindow[mid] = nums[r];
                    break;
                }
            }
            /*
            for(int i = 0; i < k; ++i)
                if(tempWindow[i] == nums[l - 1]){
                    tempWindow[i] = nums[r];
                    break;
                }
            */
        }

        // sort
        // 亲测...快排也不好使...这题还是要冒泡
        sort(tempWindow, k);

        // find the median
        if(k & 1){
            result[r - k + 1] = tempWindow[(k - 1) / 2];
        }else{
            result[r - k + 1] = (tempWindow[k / 2 - 1] + tempWindow[k / 2]) / 2;
        }

        ++r;++l;
    }
    return result;
}
