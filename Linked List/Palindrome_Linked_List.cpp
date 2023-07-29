Question Link: https://leetcode.com/problems/palindrome-linked-list/description/

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
bool isPalindrome(ListNode* head) {
    ListNode *slow = head, *fast = head, *tr = head, *tr1;
    while(slow && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverse(slow->next);

    tr1 = slow->next;
    while(tr && tr1)
    {
        if(tr->val != tr1->val) return false;
        tr = tr->next;
        tr1 = tr1->next;
    }
    return true;
}
