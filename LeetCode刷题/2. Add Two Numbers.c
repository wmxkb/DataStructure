/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* l3, *h = l1,*endnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    // 进位标志
    int carry = 0;
    //遍历l1
    while(l1){
        //每一位的和
        int nextval = (l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0) + carry;
        l1 -> val = nextval % 10;
        // 进位
        carry = nextval / 10;
        // 保存l1，用于衔接l2
        l3 = l1;
        l1 = l1 -> next;
        // l2非空，遍历
        if(l2) l2 = l2 -> next;
        // l2比l1长，剩余部分接到l1后面，继续遍历
        if(!l1 && l2){
            //衔接
            l1 = l3 -> next = l2;
            l2 = NULL;
        }
    }
    //最后一位进位操作
    if(carry){
        endnode -> val = carry;
        endnode -> next = NULL;
        l3 -> next = endnode;
    }
    return h;

}
