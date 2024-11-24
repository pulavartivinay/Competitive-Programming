Question Link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/

Solution:
ListNode* reverse(ListNode* head)
{
    ListNode *prev = NULL, *curr = head, *nxt;

    while(curr)
    {
        nxt = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nxt;
    }

    return prev;
}
int pairSum(ListNode* head) {
    if(!head) return 0;
    ListNode *slow = head, *fast = head->next;
    ListNode* head2 = NULL;
    int ans = INT_MIN;

    while(fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverse(slow->next);
    head2 = slow->next;
    while(head2)
    {
        ans = max(ans, head->val + head2->val);
        head = head->next;
        head2 = head2->next;
    }

    return ans;
}
