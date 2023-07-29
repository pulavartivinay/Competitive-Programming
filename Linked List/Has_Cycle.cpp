Question Link: https://leetcode.com/problems/linked-list-cycle/description/

Solution:
bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast;
    if(slow) fast = head->next;
    while(slow && fast && fast->next && slow != fast)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(!fast || !fast->next) return false;
    else return true;
}
