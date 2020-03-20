/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode *tp = head, *p;
    int i;
    for(p = tp, i = 0 ; p && (i < k) ; ++i, p = p -> next);
    //如果不满一组，直接返回头节点，不做更改
    if(!p && (i < k))
        return tp;
    //temp保存原头节点位置，目的是衔接各组翻转
    struct ListNode *curr, *newp = p, *temp = head;
    //将 当前组 逆序接入 下一组头部
    while(tp != p){
        //当前位置为头节点
        curr = tp;
        //令指针后移，更新头节点
        tp = tp -> next;
         //原头节点接入下一组的头部
        curr -> next = newp;
        //更新接入位置
        newp = curr;
    }
    //连接两组翻转后的部分，将后一组返回的头节点作为前一组的后继
    temp -> next = reverseKGroup(p, k);
    //返回头节点
    return newp;
}
