#include<stdio.h>
#include<stdlib.h>
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int *a = (int*)malloc((n+m)*sizeof(int));
    //这样才有意思嘛...
    //int *b = (int*)malloc(m*sizeof(int));

    int i;
    for(i = 0 ; i < n+m ; ++i){
        scanf("%d", a+i);
    }
    int j;
    for(i = 0 ; i < n + m - 1 ; ++i){
        for(j = i + 1 ; j < n + m ; ++j){
            if(*(a+i) > *(a+j)){
                *(a+i) =  *(a+i) ^ *(a+j);
                *(a+j) =  *(a+i) ^ *(a+j);
                *(a+i) =  *(a+i) ^ *(a+j);
            }
        }
        if(*(a+i)!=*(a+i-1) && i > 0)
            printf("%d ", *(a+i));
        else if(i == 0)
            printf("%d ", *(a+i));
    }
    if(*(a+n+m-1)!=*(a+n+m-2))
        printf("%d", *(a+n+m-1));

    return 0;
}
