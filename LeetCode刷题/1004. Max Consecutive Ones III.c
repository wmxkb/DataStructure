
int longestOnes(int* A, int ASize, int K){
    // result
    int res = 0;
    // 窗口左右指针
    int l, r;
    l = r = 0;
    // 滑动窗口
    while(r < ASize){
        // 如果满足 新入窗元素为 1 或者还可以把0 变 1 ， 则 窗口向右扩张，如果是0记得K--
        // 否则窗口左指针右移 ， 出窗口元素为0则需要将窗口整体右移如果新入窗元素还是0，则继续右移，不然就可以扩张最大长度了...
        (A[r] || K) ? (A[r++]? : --K) : (A[l++] ? : ++r);
        // 更新最长子数组长度...
        res = res > r - l ? res : r - l;
    }
    return res;
}
