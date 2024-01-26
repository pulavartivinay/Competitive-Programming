Question Link: https://leetcode.com/problems/reverse-nodes-in-k-group/description/

Solution:
int findlength(ListNode *head)
{
    ListNode *tr = head;
    int cnt = 0;
    while(tr)
    {
        cnt++;
        tr = tr->next;
    }

    return cnt;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    if(!head) return head;
    if(k == 1) return head;

    int len = findlength(head);

    ListNode *prev = NULL, *curr = head, *nxt;
    ListNode *newEnd = head, *last = NULL;
    ListNode * ans = NULL;
    int cnt = 0, op = 0;
    while(curr)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        cnt++;

        if(cnt == k)
        {
            if(!ans) ans = prev;

            if(last) last->next = prev;
            else last = head;
            prev = NULL;
            last = newEnd;
            newEnd = curr;
            cnt = 0;
            op++;
        }

        if(op == (len/k)) break;
    }

    if(curr) last->next = curr;

    return ans;
}
