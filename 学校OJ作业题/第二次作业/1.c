#include<stdio.h>
#include<stdlib.h>

//自定义节点
struct node{
    int data;
    struct node *next;
};

typedef struct node node;

node* fc(node* h1, node* h2);
void FreeLink(node *head);
void Print(node *result);
void Read(node *h);
int main(){
    //第一个链表
    node *h,*h1,*result;
    h = (node*)malloc(sizeof(node));
    h1 = (node*)malloc(sizeof(node));
    h->next = NULL;
    h1->next = NULL;
    //读取2个链表
    Read(h);
    Read(h1);
    //获取交集链表
    result = fc(h, h1);
    //打印
    Print(result);
    //回收
    FreeLink(h);
    FreeLink(h1);
    FreeLink(result);
    return 0;
}

void Print(node *result){
    if(result->next == NULL){
        printf("NULL");
    }else{
        result = result->next;
        while(result!=NULL){
            printf("%d ", result->data);
            result = result->next;
        }
    }
}
void Read(node *h){
    int x;
    node *p = h;
    do{
        scanf("%d", &x);
        node* t = (node*)malloc(sizeof(node));
        t->data = x;
        t->next = NULL;
        p->next = t;
        p = p->next;
    }while(getchar() != '\n');
}

node* fc(node* h1, node* h2){
    node* head = (node*)malloc(sizeof(node));
    node* tmp = head, *s;
    tmp->next = NULL;
    node* p1 = h1->next, * p2 = h2->next;
    int last = p1->data - 1;//nice
    while (p1 != NULL)
    {
        while (p2 != NULL)
        {
            if (p2->data == p1->data && p2->data != last)
            {
                s = (node*)malloc(sizeof(node));
                s->data = p1->data;
                s->next = NULL;
                tmp->next = s;
                tmp = s;
                last = p1->data;
                break;
            }
            p2 = p2->next;
        }

        p1 = p1->next;
        p2 = h2->next;
    }

    return head;
}

void FreeLink(node *head)
{
    node *p;
    while(head != NULL)
    {
        p = head;
        head = p -> next;
        free(p);
    }

}
