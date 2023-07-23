Question Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

Solution:
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(!head->next) return NULL; // base case n = 1
    ListNode *first = head, *second = head;
    for(int i=0;i<n;i++)
    {
        second = second->next;
    }
    if(!second) return head->next; // remove the first element of linked list
    while(second->next != NULL)
    {
        first = first->next;
        second = second->next;
    }
    first->next = first->next->next;
    return head;
}
