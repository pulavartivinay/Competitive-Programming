Question Link: https://leetcode.com/problems/linked-list-cycle/

Solution:

bool hasCycle(ListNode *head) 
{
    ListNode* slow = NULL;
    if(head) slow = head;
    else return 0;
    ListNode* fast = NULL;
    if(head->next) fast = head->next;
    else return 0;
    while(fast->next != NULL && fast->next->next != NULL && slow != fast)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(slow == fast) return 1;
    else return 0;
}
