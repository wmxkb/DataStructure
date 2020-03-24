

int removeElement(int* nums, int numsSize, int val){
    //存储长度 和 更改的位置
    int Len = numsSize, start = 0;
    for(int i = 0 ; i < numsSize ; ++i){
        //如果元素是需要删除的元素，长度 - 1
        if(nums[i] == val){
            --Len;
        //否则将元素移动到新的位置
        }else{
            nums[start++] = nums[i];
        }
    }
    return Len;
}
