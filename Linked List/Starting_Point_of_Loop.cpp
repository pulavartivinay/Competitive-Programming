Question Link: https://leetcode.com/problems/linked-list-cycle-ii/description/

Solution:
ListNode *detectCycle(ListNode *head) {
    if(!head) return NULL;
    ListNode *slow = head, *fast = head;

    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }

    if(!fast || !fast->next) return NULL;

    fast = head;
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
