// 求最大值
#define max(x, y)(x > y ? x : y)

// 滑动窗口问题
// 这里的主要思想就是找到当前窗口内字母的最大频数，于历史最大值比较并不断更新窗口。
int characterReplacement(char * s, int k){
    //左右指针
    int l, r;
    l = 0; r = 0;
    //统计字母出现频率
    int fre[256] = {0};
    // 最长子串的长度
    int maxlen = 0;
    // s长度
    int slen = strlen(s);
    // maxc
    int maxc = 0;
    while(r < slen){
        // 进入窗口，频率 + 1
        ++fre[s[r]];
        // 更新频率最大的字符
        maxc = max(maxc, fre[s[r]]);
        // 窗口根据历史最大频率字符数量不断右移
        while(maxc + k < r - l + 1){
            --fre[s[l++]];
        }
        //窗口扩大
        ++r;
    }
    //最大长度即最后时刻窗口大小
    maxlen = slen - l;
    return maxlen;
}
