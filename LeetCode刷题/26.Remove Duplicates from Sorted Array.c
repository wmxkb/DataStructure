


int removeDuplicates(int* nums, int numsSize){
    //如果是空数组，直接返回长度0
    if(!numsSize)
        return 0;
    //唯一用到的空间，记录更新数组的位置
    int len = 0;
    for(int i = 1 ; i < numsSize ; ++i){
        //遇到新的非重复项，更新数组
        if(nums[i] != nums[len]){
            nums[++len] = nums[i];
        }
    }
    return len + 1;
}
