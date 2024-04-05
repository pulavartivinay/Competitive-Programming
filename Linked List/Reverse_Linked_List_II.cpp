Question Link: https://leetcode.com/problems/reverse-linked-list-ii/description/?envType=list&envId=xler4hke

Solution:
ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(!head) return head;
    int len = 1;

    ListNode *prev = NULL, *curr = head, *nxt;
    ListNode *b1 = NULL, *b2 = NULL, *newEnd = NULL;

    while(curr)
    {
        nxt = curr->next;

        if(len == left-1) b1 = curr;
        if(len == left) newEnd = curr;
        if(len == right+1) b2 = curr;

        if(left <= len && len <= right) {
            curr->next = prev;
            prev = curr;
            curr = nxt;
        } else {
            curr = curr->next;
        }
        len++;
    }

    if(b1) b1->next = prev;
    else head = prev;
    if(b2) newEnd->next = b2;

    return head;
}
