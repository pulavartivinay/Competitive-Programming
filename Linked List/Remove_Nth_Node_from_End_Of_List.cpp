Question Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

Solution:
ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode *slow = head, *fast = head;

    int i=0;
    while(i < n)
    {
        fast = fast->next;
        i++;
    }
    if(!fast) return head->next;

    while(fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    ListNode* tmp = slow->next;
    slow->next = tmp->next;
    delete tmp;

    return head;
}
