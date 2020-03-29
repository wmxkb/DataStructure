#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// 状态定义
#define OK 1
#define True 1
#define False 0
#define ERROR 0
#define OVERLOW -1

// 用户可在255以内定义最大串长
#define MAXSTRLEN 255

// 0号单元存放串的长度, 故长度为MAXSTRLEN + 1
typedef unsigned char SString[MAXSTRLEN + 1];

// 状态
typedef int Status;

// 生成一个值等于chars的串
Status StrAssign(SString T, char chars[]){
    // 长度超限
    if(strlen(chars) > MAXSTRLEN){
      printf("error: too long to assign\n");
      return ERROR;
    }else{
        // 存放长度
        T[0] = strlen(chars);
        //复制
        for(int i = 1 ; i <= T[0] ; ++i)
          T[i] = *(chars + i - 1);
        return OK;
    }
}

//由串S复制得到串T
Status StrCopy(SString &T, SString S){
  for(int i = 0 ; i <= S[0] ; ++i){
    T[i] = S[i];
  }
  return OK;
}

// 判断S是否为空
Status StrEmpty(SString S){
  return S[0] == 0 ? True : False;
}

// 比较串的大小， 如果S > T , 返回值 > 0； 如果S == T， 返回 0；如果S < T ，返回值 < 0
Status StrCompare(SString S, SString T){
  int i;
  for(i = 1 ; i <= S[0] && i <= T[0] ; ++i){
    if(S[i] != T[i]) return S[i] - T[i];
  }
  return S[0] - T[0];
}

// 返回串的长度
int StrLength(SString S){
  return S[0];
}

// 清空串
Status ClearString(SString &S){
  S[0] = 0;
  return OK;
}

// 连接两串返回新串,未截断返回True,截断返回False
Status Concat(SString &T, SString S1, SString S2){
  // 未截断
  if(S1[0] + S2[0] <= MAXSTRLEN){
    T[0] = S1[0] + S2[0];
    // S1
    for(int i = 1 ; i <= S1[0] ; ++i){
      T[i] = S1[i];
    }
    // S2
    for(int j = S1[0] + 1 ; j <= T[0] ; ++j){
      T[j] = S2[j - S1[0]];
    }
    return True;
  // S2截断
  }else if(S1[0] < MAXSTRLEN){
    T[0] = MAXSTRLEN;
    // S1先赋给T
    for(int i = 1 ; i <= S1[0] ; ++i){
      T[i] = S1[i];
    }
    // S2剩余部分
    for(int j = S1[0] + 1 ; j <= MAXSTRLEN ; ++j){
      T[j] = S2[j - S1[0]];
    }
    return False;
  // S1、S2截断或者S2完全截断
  }else{
    T[0] = MAXSTRLEN;
    // S1
    for(int i = 1 ; i <= T[0] ; ++i){
      T[i] = S1[i];
    }
    return False;
  }
}

// 用Sub返回特定子串(pos开始，长度为len)
int SubString(SString &Sub, SString S, int pos, int len){
  if((pos < 1) || (pos > S[0]) || (len < 0) || (len > S[0] - pos + 1))
		return ERROR;
  Sub[0] = len;
  for(int i = pos ; i < pos + len ; ++i){
    Sub[i] = S[i];
  }
  return OK;
}


// 返回子串在主串pos后第一次出现的位置（Sunday）
Status Index(SString S, SString T, int pos){
  int len1 = S[0], len2 = T[0];
  // 获得偏移量数组
  int * next = (int*)malloc(sizeof(int) * len2);
  for(int k = 0 ; k < len2 ; ++k){
    next[k] = len2 - k;
  }
  int i = pos, j = 0;
  while(i < len1 && j < len2){
  // 依次判断，相等 i 、 j自增
    if(S[i + 1] == T[j + 1]){
      ++i;
      ++j;
    }else{
      // 如果索引下标超出范围，结束搜索
      if(i + len2 - j > len1)
        break;
      // 获得元素在T串中的索引（逆序第一个）
      int index = -1;
      for(int l = len2 - 1 ; l >= 0 ; --l){
        if(S[i + len2 - j] == T[l]){
          index =  l;
          break;
        }
      }
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
  return 0;
}

// 插入
Status StrInsert(SString &S, int pos, SString T){
  if( (pos < 1) || (pos > S[0] + 1) )
		return ERROR;
  // 完全插入
  if(S[0] + T[0] <= MAXSTRLEN){
    for(int i = S[0] ; i >= pos ; --i){
      S[i+T[0]] = S[i];
    }
		for(int i = pos ; i < pos + T[0] ; ++i)
			S[i] = T[i - pos + 1];
		S[0] += T[0];
		return True;
  }else{
    // 部分插入
    // 若T完整插入，在T后插入剩余S
    for(int i = MAXSTRLEN ; i >= pos + T[0] ; --i){
      S[i] = S[i - T[0]];
    }
    // pos处插入T
		for(int i = pos ; i < pos + T[0] && i <= MAXSTRLEN ; ++i){
      S[i] = T[i - pos + 1];
    }
		S[0] = MAXSTRLEN;
		return False;
  }
}
// 删除指定位置指定长度子串
Status StrDelete(SString &S, int pos, int len){
  if( (pos < 1) || (pos > S[0] - len + 1) || (len < 0) )
    return ERROR;
  // 拼接
  for(int i = pos + len ; i <= S[0] ; ++i)
    S[i - len] = S[i];
  // 更新长度
  S[0] -= len;
  return OK;
}

// 用V替换S中所有出现的T
Status Replace(SString &S, SString T, SString V) {
  // 从串S的第一个字符起查找串T
  int i = 1;
	Status k;
  // 如果T是空串 ，返回错误
	if(StrEmpty(T)) return ERROR;
	do{
    // 保存i后第一个子串的位置
    i = Index(S, T, i);
    // 若找到子串
    if(i) {
      // 删除T
		  StrDelete(S, i, StrLength(T));
      // 插入V
		  k = StrInsert(S, i, V);
      // 不能完全插入
		  if(!k)
			   return ERROR;
      // 查找下一个T
		  i += StrLength(V);
		}
	}while(i);
	return OK;
}

// 输出字符串T。
void StrPrint(SString T) {
	for( int i = 1 ; i <= T[0] ; ++i )
		printf("%c ", T[i]);
	printf("\n");
}
