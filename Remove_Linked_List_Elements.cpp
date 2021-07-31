Question Link: https://leetcode.com/problems/remove-linked-list-elements/

Solution:

ListNode* removeElements(ListNode* head, int val) 
{
    while(head != NULL && head->val == val)
    {
        head = head->next;
    }
    if(head == NULL) return NULL;
    ListNode* prev = head;
    ListNode* curr = head->next;
    while(curr != NULL)
    {
        if(curr->val == val)
        {
            prev->next = curr->next;
            curr = prev->next;
        }
        else
        {
            prev = prev->next;
            curr = curr->next;
        }
    }
    return head;
}
