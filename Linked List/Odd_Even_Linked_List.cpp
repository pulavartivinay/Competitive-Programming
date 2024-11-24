Question Link: https://leetcode.com/problems/odd-even-linked-list/description/

Solution:
ListNode* oddEvenList(ListNode* head) {
    if(!head || !head->next || !head->next->next) return head;
    ListNode *odd = head, *even = head->next, *prev = NULL, *merge_node = head->next;

    while(odd && even)
    {
        odd->next = even->next;
        if(!odd->next) prev = odd;
        odd = odd->next;

        if(odd)
        {    
            even->next = odd->next;
            even = even->next;
        }
    }

    if(odd) odd->next = merge_node;
    else prev->next = merge_node;

    return head;
}
