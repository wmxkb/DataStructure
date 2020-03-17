/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
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
/*
    //l1 非空
    while(l1 != NULL){
        l3 = l3 -> next = l1;
        l1 = l1 -> next;
    }
    //l2非空
    while(l2 != NULL){
        l3 = l3 -> next = l2;
        l2 = l2 -> next;
    }
*/
    //之前写的略有多余了
    l3 -> next = l1 ? l1 : l2;
    //返回不带头节点的新链表
    return newp -> next;
}
