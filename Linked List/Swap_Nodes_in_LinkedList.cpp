Question Link: https://leetcode.com/problems/swap-nodes-in-pairs/description/?envType=list&envId=xler4hke

Solution:ListNode* swapPairs(ListNode* head) {
    if(!head) return head;
    if(!head->next) return head;

    ListNode* first = head;
    ListNode* second = head->next;
    ListNode* rem = swapPairs(second->next);

    second->next = first;
    first->next = rem;

    return second;
}
