#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//自定义节点
struct node{
    int data;
    struct node *next;
};
typedef struct node node;

void fc(node* L,int n){
    node* p=L,*r;
    int *q,m;
    q=(int*)malloc(sizeof(int)*(n+1));
    memset(q,0,sizeof(n+1));
    while(p->next!=NULL){
        m = p->next->data>0 ? p->next->data: -p->next->data;
        if(*(q+m)==0){
            *(q+m)=1;
            p=p->next;
        }else{
            r=p->next;
            p->next=r->next;
            free(r);
        }
    }
    free(q);
}

void Read(node *h, int n){
    int x;
    node *p = h;
    int i;
    for(i = 0 ; i < n ; ++i){
        scanf("%d", &x);
        node* t = (node*)malloc(sizeof(node));
        t->data = x;
        t->next = NULL;
        p->next = t;
        p = p->next;
    }
}
void Print(node *result){
        result = result->next;
        while(result!=NULL){
            printf("%d ", result->data);
            result = result->next;
        }
}
int main(){
    node* h = (node*)malloc(sizeof(node));
    h->next = NULL;
    int n;
    scanf("%d", &n);
    Read(h, n);
    fc(h,n);
    Print(h);
    return 0;
}
