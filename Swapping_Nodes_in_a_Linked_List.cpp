Question Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

Solution:

ListNode* swapNodes(ListNode* head, int k) 
{
    k = k-1;
    ListNode* travel = head;
    int count = 0;
    while(travel != NULL)
    {
        count++;
        travel = travel->next;
    }
    int last = (count - k - 1);
    ListNode* first = NULL;
    ListNode* second = NULL;
    travel = head;
    int temp = 0;
    while(travel != NULL)
    {
        if(temp == k) first = travel;
        if(temp == last) second = travel;
        travel = travel->next;
        temp++;
    }
    swap(first->val,second->val);
    return head;
}
