#include<stdio.h>
#include<stdlib.h>
//就这？？？
int main(){
    int n;
    scanf("%d", &n);
    int *a = (int*)malloc(n*sizeof(int));
    int i;
    for(i = 0 ; i < n ; ++i){
        scanf("%d", a + i);
    }
    int temp = a[0], count = 1;
    for(i = 1 ; i < n ; ++i){
        if(!count){
            temp = a[i];
            count = 1;
            continue;
        }
        if(a[i] == temp){
            ++count;
        }
        else{
            --count;
        }
    }
    int N = 0;
    for(i = 0 ; i < n ; ++i){
        if(*(a + i) == temp)
            ++N;
    }
    if(N > n / 2)
        printf("%d\n", temp);
    else
        printf("-1\n");
    return 0;
}
