/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    //设置工作指针指向头节点
    struct ListNode* p = head;
    //获得链表长度
    int count = 0;
    while(p != NULL){
        ++count;
        p = p -> next;
    }
    //获取第length - n个节点的地址
    p = head;
    int i = 1;
    while(i++ < count - n){
        p = p -> next;
    }
    //如果要删除的是头节点
    if(count == n){
        struct ListNode* s = head;
        head = head -> next;
        free(s); //释放
        return head;
    }
    //其余情况
    struct ListNode* p1 = p -> next;
    p -> next = p -> next ->next;
    free(p1);//释放
    return head;
}
