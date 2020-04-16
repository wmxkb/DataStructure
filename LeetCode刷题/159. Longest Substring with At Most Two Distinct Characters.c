// select the max
#define maxlen(x, y)(x > y ? x : y)
// 滑动窗口
int lengthOfLongestSubstringTwoDistinct(char * s){
    // 左右指针
    int l, r;
    l = r = 0;
    // 获得长度
    int len = strlen(s);
    // 存储字符出现频率
    int fre[256] = {0};
    // 不同字符个数
    int count = 0;
    // result
    int res = 0;
    while(r < len){
        // 窗口内出现一个新字符，计数+1
        if(!fre[s[r++]]++){
            count++;
        }
        // 字符种类 > 2, 窗口左边界右移，缩小窗口
        while(count > 2){
            if(--fre[s[l++]] == 0) count--;
        }
        // 更新最大值
        res = maxlen(res, r - l);
    }
    return res;
}
