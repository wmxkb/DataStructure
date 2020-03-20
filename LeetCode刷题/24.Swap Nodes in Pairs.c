/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* p , *pre, *result;
    //如果是空链表或单节点，直接返回。
    if(!head || !(head ->next)){
        return head;
    }else
        //返回链表的头节点为第二个节点
        result = head -> next;
    //存储前一个节点
    pre = NULL;
    //遍历
    while(head){
        //剩余单独节点，跳出循环
        if(head -> next == NULL)
            break;
        //交换
        p = head -> next;
        head -> next = p -> next;
        p -> next = head;
        //除了首元，其余元素都有前一个节点（偶数节点）
        if(pre) pre -> next = p;
        //交换后与前一个节点接上
        pre = head;
        //向前遍历
        head = head -> next;

    }
    return result;
}
