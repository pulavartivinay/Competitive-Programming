Question Link: https://leetcode.com/problems/odd-even-linked-list/description/?envType=list&envId=xler4hke

Solution:
ListNode* oddEvenList(ListNode* head) {
    if(!head || !head->next || !head->next) return head;

    ListNode *odd = head, *even = head->next;
    ListNode *even_start = even;

    while(odd->next && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = even_start;

    return head;
}
