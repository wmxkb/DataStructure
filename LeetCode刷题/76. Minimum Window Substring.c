// 求最小窗口
int min(int x, int y, int *ml, int *mr, int l, int r){
    if(y < x){
        *ml = l; *mr = r;
        return y;
    }else{
        return x;
    }
}


char * minWindow(char * s, char * t){
    // 左右指针
    int l, r;
    l = 0; r = 0;
    // 字符串长度
    int len1, len2;
    len1 = strlen(s); len2 = strlen(t);
    // 存储字母出现频率
    int fre[128] = {0};
    for(int i = 0; i < len2; ++i){
        ++fre[t[i]];
    }
    // 存储T中元素需求量
    int cnt = len2;
    // 最小串
    int ml, mr, mw;
    ml = 0; mr = -1; mw = len1 * 2;
    //滑动窗口
    while(r < len1){
        // 进入窗口，fre - 1
        --fre[s[r]];
        // 注意T中元素不一定是所需的T中元素
        // 如果是所需的T中元素， fre仍然大于0， 需求量 - 1
        if(fre[s[r]] >= 0) --cnt;
        // 包含所有T中元素
        while(cnt == 0){
            // 保存最小子串相关信息
            mw = min(mw, r - l + 1 , &ml, &mr, l, r);
            // 左指针右移，fre + 1，且如果出窗口的是所需的T中元素，需求量 + 1
            if(++fre[s[l++]] > 0) ++cnt;
        }
        ++r;
    }

    // 子串
    char *result = (char*)malloc(sizeof(char) * (mw + 1));
    // 如果 S 中不存这样的子串，则返回空字符串 ""
    if(mw == len1 * 2) return "";
    // 截取
    for(int i = ml ; i <= mr + 1 ; ++i){
        result[i - ml] = s[i];
    }
    result[mw] = '\0';
    return result;
}
