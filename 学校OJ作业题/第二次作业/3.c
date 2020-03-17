#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int GetMax(int a[],int len) {
    int m = a[0];
    int i;
    for (i = 1;i< len;i++)
        m = m < a[i] ? a[i] : m;
    return m;
}
int GetMin(int a[],int len) {
  int m = GetMax(a,len);
  if (m <= 0){
      return 1;
  }else{
      int* t = (int*)malloc(sizeof(int)*(m + 1));
      memset(t,0,sizeof(int)*(m+1));
      int i;
      for (i = 0; i <len; i++){
          if (a[i]>0){
              t[a[i]] = 1;
          }
      }
      for (i = 1; i <= m;i++) {
        if (t[i] == 0){
            return i;
        }
      }
      return m + 1;
  }
}
int main(){
    int n;
    scanf("%d", &n);
    int *a = (int*)malloc(sizeof(int)*n);
    int i;
    for(i = 0; i < n ; ++i){
        scanf("%d", a+i);
    }
    printf("%d",GetMin(a, n));
}
