// select the min
#define minres(x, y)(x < y ? x : y);
// 固定窗口大小的滑窗问题
int minSwaps(int* data, int dataSize){
    // 首先要获取1的个数以固定窗口大小
    int i = 0, width = 0;
    while(i++ < dataSize) data[i - 1] == 0 ?  : ++width;
    // 窗口左右指针
    int l, r;
    l = r = 0;
    // 统计窗口内0的个数
    int count = 0;
    // result
    int res = width;
    while(r < dataSize){
        // 扩张窗口到指定大小
        if(r - l < width)
            data[r++] ? : count++;
        else{
            // 更新窗口内‘0’个数最小值
            res = minres(res, count);
            // 窗口整体向右滑动
            data[l++] ? : --count;
            data[r++] ? : ++count;
        }
    }
    //
    res = minres(res, count);
    return res;
}
