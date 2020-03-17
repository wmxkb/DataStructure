
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


void dfs(int n, int i, int l, int r, char *part, char **result, int *count){
    //如果左括号数量 < n， 插入左括号
    if(l < n){
        //插入'('
        part[i] = '(';
        //标记字符串结尾
        part[i + 1] = '\0';
        dfs(n, i + 1, l + 1, r, part, result, count);
    }

    //如果左括号数量 > 右括号数量，插入右括号
    if(l > r){
        //插入')'
        part[i] = ')';
        //标记字符串结尾
        part[i + 1] = '\0';
        dfs(n, i + 1, l, r + 1, part, result, count);
    }

    //如果括号数量 == 2n
    //说明已经完成一种情况，分配空间，连接字符串
    //返回，继续遍历
    if(l == n && r == n){
         //这里要注意，count是需要进行更新的，所以需要指针传值
         result[(*count)]=(char*)malloc(sizeof(char)*(2*n+1));
         strcpy(result[(*count)++],part);
        return;
    }
}


char ** generateParenthesis(int n, int* returnSize){
    //用l, r记录左右括号已使用数目
    int l, r;
    l = r = 0;
    //cnt记录类型数量
    int count = 0;
    //i是当前元素的下标
    int i = 0;
    //创建二维数组存储结果
    char **result = (char **)malloc(sizeof(char *) * 2000);
    //创建part存储每一种情况
    char *part = (char *)malloc(sizeof(char)*(2 * n + 1));
    //开始递归计算
    dfs(n, i, l, r, part, result, &count);
    //返回结果类型数量
    *returnSize = count;
    //返回结果
    return result;

}
