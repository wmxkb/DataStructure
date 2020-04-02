// 滑动窗口解题
bool checkInclusion(char * s1, char * s2){
    // 长度
    int len1 = strlen(s1), len2 = strlen(s2);
    // 用于计数
    int cnt = len1;
    // 左右指针
    int l, r;
    l = 0; r = 0;
    // 存储s1字母出现频率
    int fre[256] = {0};
    //记录频率
    for(int i = 0; i < len1; ++i){
        ++fre[s1[i]];
    }
    // 遍历开始
    while(r < len2){
        // 新入窗的元素是s1中的元素，计数-1
        if(--fre[s2[r]] >= 0){
            --cnt;
        }
        //滑动窗口
        if(r > len1 - 1){
            //出窗元素是s1中的元素，计数+1
            if(++fre[s2[l++]] > 0){
                ++cnt;
            }

        }
        //当前窗口符合要求，返回true
        if(cnt == 0){
            return true;
        }
        //右移窗口
        ++r;
    }
    //执行到这一步，说明不符合，返回false
    return false;
}
