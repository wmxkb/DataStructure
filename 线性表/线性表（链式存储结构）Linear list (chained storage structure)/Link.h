#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
//单链表的存储结构定义
struct Node{
    DataType data; //数据域
    struct Node *next; //指针域
};
typedef struct Node Node;

//初始化链表
Node *InitList(Node *head){//传入头节点
    head = (Node*)malloc(sizeof(Node)); //给头节点分配内存空间
    head -> next = NULL; //将指针域置为NULL，避免错误访问
    return head; //将分配好空间后的头节点返回
}

//求线性表长度 = 总空间大小/sizeof（Node） - 1
int Length(Node *head){
    if(head == NULL){
        printf("---线性表未创建---");
        return -1;
    }
    int count = 0; //计数变量count = 0
    Node *p = head -> next; //定义p指针指向第一个节点
    while(p != NULL){
        p = p -> next; //向前传递
        ++count; //计数
    }
    return count; //返回长度
}

//按位查找
DataType Get(Node *head, int i){
    Node *p = head -> next; //定义p指针指向第一个节点
    int count = 1;
    while(count < i && p != NULL){//开始计数，直到第i个节点跳出循环
        ++count;
        p = p -> next;
    }
    if(p == NULL){ //如果节点为空，返回信息，退出
        printf("访问错误\n");
        exit(0);
    }
    return p -> data; //返回节点数据域值
}

//按值查找
int Locate(Node *head, DataType x){
    Node *p = head -> next; //定义p指针指向第一个节点
    int count = 1; //从第一个节点开始计数
    while(p != NULL){
        if(p -> data == x) //如果找到了，返回节点位置
            return count;
        ++count;
        p = p -> next;
    }

    return 0; //未找到，返回0
}

//插入元素
void Insert(Node *head, int i, DataType x){
    Node *p = head; //p指向头节点，因为第一个节点要通过头节点来插入
    int count = 0;

    while(p != NULL && count < i - 1){
        p = p -> next;
        ++count;
    }
    //跳出循环时p指向第i - 1个节点

    if(p == NULL){ //如果第i-1个节点为空，则插入节点失败，返回
        printf("插入节点失败");
        exit(-1);
    }
    //插入第i个节点
    Node *s = (Node*)malloc(sizeof(Node));
    s -> data = x;
    s -> next = p -> next;
    p -> next = s;
}
//创建新节点
Node *Create_Node(DataType data){
    Node* np = (Node*)malloc(sizeof(Node));//为新节点开辟空间
    np->next = NULL;     //新节点指向NULL;
    np->data = data;
    return np; //返回新节点地址
}

//插入数据(头插法)
void Push_Head(Node *head, DataType data){
    Node *np = Create_Node(data); //创建一个新的节点
    np->next = head -> next;
    head->next = np;
}

//插入数据(尾插法)
void Push_Tail(Node *head, DataType data){
    Node* p = head;
    while (p -> next != NULL){//找到最后一个节点
        p = p -> next;
    }
    Node *np = Create_Node(data);
    p -> next = np; //插入元素
}

//建立单链表（尾插法）
Node *Creat(Node *head, DataType a[], int n){
    head = InitList(head);

    int i;
    for(i = 0 ; i < n ; ++i){ //循环插入元素
        Push_Tail(head, a[i]); //尾插
    }
    return head;
}

//删除节点
DataType Delete(Node *head, Node *s){
    Node* p = s; //把要删除的节点保存起来
    DataType x = p -> data;
    while(head -> next != s){
        head = head -> next;
    }
    head -> next = s -> next; //连接它的前节点与后节点
    free(p); //释放
    return x;
}

//按位删除节点
DataType Delete_L(Node *head, int i){
    Node *p = head;
    int len = Length(head);
    if(i > len){
        printf("删除失败");
        exit(-1);
    }
    int j;
    for(j = 1 ; j < i ; ++j){
        p = p -> next;
    }
    int x = Delete(head, p -> next); //这里只是为了用上Delete(),最好像注释那样写
    /*
    Node *q = p -> next;
    int x = q -> data; //存储被删除节点的数据
    p -> next = q -> next; //取出q节点
    free(q); //释放空间
    */
    return x; //返回被删除节点的数据
}


//摧毁线性表
Node *Destroy_List(Node *head){
    Node* p = head;
    while(p != NULL){//依次回收节点
        p = head -> next;
        free(head);
        head = p;
    }
    return NULL; //返回后许重新赋值给头节点
}

//Clear_List()
void Clear_List(Node *head){
    Destroy_List(head -> next);//摧毁除头节点以外其他节点
    head -> next = NULL; //给头节点指针域置空
}

int List_Empty(Node *head){
    return Length(head) > 0; //空 0 非空 1
}

DataType Get_Prev(Node *head, DataType x){
    int l = Locate(head, x) - 1; //获取前一个元素的序号
    if(l > 0)
        return Get(head,l);  //通过Get得到数据
    else{
        printf("当前元素已经是第一个元素");
        exit(-1);
    }
}

DataType Get_Next(Node *head, DataType x){
    int l = Locate(head, x) + 1; //获取后一个元素的序号
    if(l < Length(head))
        return Get(head,l);  //通过Get得到数据
    else{
        printf("当前元素已经是最后一个元素");
        exit(-1);
    }
}

void Traverse_Link(Node* head, void visit()){
    Node *p = head -> next;
    while(p != NULL){
        visit(p); //调用自定义功能函数
        p = p -> next;
    }
}
