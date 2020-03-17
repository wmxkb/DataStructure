#include<stdio.h>


int main(){
    int n, e;
    scanf("%d %d",&n,&e);
    int i;
    int flag = 1;
    int out = 0;
    int x;
    for(i = 0; i < n; ++i){
        scanf("%d", &x);
        if(x == e && flag){
    flag = 0;
    out = i + 1;
        }
    }
    printf("%d", out);
    return 0;
}
