// sunday算法求解
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 获得偏移量数组
void get_next(int * next, int len){
    for(int i = 0 ; i < len ; ++i){
        next[i] = len - i;
    }
}

// 逆序判断元素字符是否在字符串中，在的话返回第一个下标，否则返回-1
int In(char c, char * needle){
    for(int i = strlen(needle) - 1 ; i >= 0 ; --i){
        if(c == needle[i])
            return i;
    }
    return -1;
}

int strStr(char * haystack, char * needle){
    // 获得字符串长度
    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    // 如果是空串，返回0
    if(len1 == 0 && len2 == 0)
        return 0;
    // 获得偏移量数组
    int * next = (int*)malloc(sizeof(int) * len2);
    get_next(next, len2);

    int i = 0, j = 0;
    while(i < len1 && j < len2){
        // 依次判断，相等 i 、 j自增
        if(haystack[i] == needle[j]){
            ++i;
            ++j;
        }else{
        // 如果索引下标超出范围，结束搜索
			      if(i + len2 - j > len1)
				        break;
            // 获得元素在needle串中的索引（逆序第一个）
            int index = In(haystack[i + len2 - j], needle);
            // 元素在串内，按偏移量数组进行偏移
            if(index != -1){
                i += (next[index] - j);
                j = 0;
            }else
            // 不在串内，直接整体移到该元素后
				        i += len2 + 1 - j;
        }
    }
    // 成功匹配
    if(j == len2)
        return i - len2;
    return -1;
}

// 测试
int main(){
	char a[] = "mississippi", b[] = "sipp";
	printf("%d",strStr(a, b));
	return 0;
}
