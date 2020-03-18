/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* sortList(struct ListNode* head);
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    //定义工作指针， 新链表的指针
    struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode)), * newp;
    //保存头节点
    newp = p;
    //置空
    p -> next = NULL;
    //合并K个链表
    for(int i = 0 ; i < listsSize ; ++i){
        p -> next = lists[i];
        while(p -> next != NULL){
            p = p -> next;
        }
    }
    //进行归并排序
    newp = sortList(newp -> next);
    return newp;
}

//归并排序
struct ListNode* sortList(struct ListNode* head) {
    struct ListNode* merge2Lists(struct ListNode*, struct ListNode*);
    //如果是空链表，或者单节点，直接返回
    if (head == NULL || head->next == NULL) return head;
    //定义工作指针p,以及两个定位的指针
    struct ListNode p, *all = &p, *half = &p;
    p.next = head;
    //all更新速率为half 2倍，借此定位half到链表中间节点
    while (all->next && all->next->next) {
        all = all->next->next;
        half = half->next;
    }
    //保存后半段链表
    struct ListNode* next = half->next;
    //截断
    half->next = NULL;
    //继续划分，直到不能再划分为止
    struct ListNode* partOne = sortList(head);
    struct ListNode* partTwo = sortList(next);
    //归并
    return merge2Lists(partOne, partTwo);
}

//将两非递减链表合并为一个非递减新链表
struct ListNode* merge2Lists(struct ListNode* l1, struct ListNode* l2){
    //定义一个新链表
    struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode)), *newp;
    l3 -> val = 0;
    newp = l3;
    l3 -> next = NULL;
    //l1 、 l2 均非空 ，需要进行比较
    while(l1 != NULL && l2 != NULL){
        if(l1 -> val <= l2 -> val){
            //l1 接入 newp 尾部，工作指针l3向前移动
            l3 = l3 -> next = l1;
            l1 = l1 -> next;
        }else{
            l3 = l3 -> next = l2;
            l2 = l2 -> next;
        }
    }
    l3 -> next = l1 ? l1 : l2;
    //返回不带头节点的新链表
    return newp -> next;
}
