#define max(x, y)(x > y ? x : y)

// 滑动窗口算法
int lengthOfLongestSubstring(char * s){
    // 定义左右指针
    int l, r;
    l = 0; r = -1;
    //cnt存储出现次数
    int cnt[256] = {0};
    //获取长度
    int len = strlen(s);
    int maxsize = 0;
    while(l < len){
        // 边界限定以及右指针移动条件
        if( (r + 1 < len) && (cnt[s[r + 1]] == 0) )
            ++cnt[s[++r]];
        else
        //左值针移动条件刚好与右指针互斥，即有重复元素移动左值针
            --cnt[s[l++]];
        maxsize = max(maxsize, r - l + 1);
    }
    return maxsize;
}
