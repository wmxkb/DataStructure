
// 滑窗
int numKLenSubstrNoRepeats(char * S, int K){
    // 存储字符出现频数
    int fre[256] = {0};
    // 窗口左右指针
    int l, r;
    l = r = 0;
    // S长度
    int len = strlen(S);
    // 窗口内不同字符个数
    int count = 0;
    // 当前窗口宽度
    int width = 0;
    // result
    int res = 0;
    while(r < len){
        // 一开始先扩展窗口到宽度为K
        if(width < K){
            // 频数为0，说明入窗的是新的字符，频数 + 1 ， 不同字符计数 + 1
            if(fre[S[r++]]++ == 0) count++;
            // 宽度 + 1
            width++;
        }else{ // 宽度为K后固定宽度滑动窗口
            // 字符出窗后窗内无该字符， 不同字符计数 - 1
            if(--fre[S[l++]] == 0) count--;
            if(fre[S[r++]]++ == 0) count++;
        }
        // 不同字符计数 == K， 满足条件， res++
        if(count == K) res++;

    }
    return res;
}
