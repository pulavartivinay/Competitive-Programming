Question Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

Solution:

ListNode* deleteDuplicates(ListNode* head) 
{
    if(head == NULL || head->next == NULL) return head;
    ListNode* curr = head;
    ListNode* ans = curr;
    while(curr != NULL && curr->next != NULL)
    {
        ListNode* after = curr->next;
        if(curr->val == after->val)
        {
            curr->next = after->next;
        }
        else curr = curr->next;
    }
    return ans;
}
