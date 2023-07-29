Question Link: https://leetcode.com/problems/rotate-list/description/

Solution:
ListNode* rotateRight(ListNode* head, int k) {
    if(!head) return head;
    int len = 1;
    ListNode *tr = head, *prev = NULL;
    while(tr->next)
    {
        len++;
        tr = tr->next;
    }

    tr->next = head;

    k = (k%len);
    int steps = (len - k);
    while(steps > 0)
    {
        prev = head;
        head = head->next;
        steps--;
    }
    if(prev) prev->next = NULL;

    return head;
}
