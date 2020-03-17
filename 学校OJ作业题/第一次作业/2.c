#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int maxnum = 0;
    int i;
    int x;
    for(i = 0; i < n; ++i){
        scanf("%d", &x);
        if(x > maxnum)
            maxnum = x;
    }
    printf("%d", maxnum);
    return 0;
}
