Question Link: https://leetcode.com/problems/merge-two-sorted-lists/description/

Solution:
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    if(!list1) return list2;
    if(!list2) return list1;

    ListNode* curr = NULL;
    if(list1->val <= list2->val) 
    {
        curr = list1;
        list1 = list1->next;
        curr->next = mergeTwoLists(list1, list2);
    }
    else
    {
        curr = list2;
        list2 = list2->next;
        curr->next = mergeTwoLists(list1, list2);
    }

    return curr;
}
