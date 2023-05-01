Question Link: https://leetcode.com/problems/reverse-nodes-in-k-group/

Solution:

SinglyLinkedListNode* ReverseKLL(SinglyLinkedListNode* start, int k) {
    if((start == NULL) || (start->next == NULL) || (k == 1)) return start;
    int l = 0;
    SinglyLinkedListNode* tr = start;
    while(tr)
    {
        tr = tr->next;
        l++;
    }
    SinglyLinkedListNode* dummy = new SinglyLinkedListNode(0);
    dummy->next = start;
    
    SinglyLinkedListNode* prev = dummy, *curr, *nxt;
    while(l > 0)
    {
        curr = prev->next;
        nxt = curr->next;
        for(int i=1;i<min(l,k);i++)
        {
            curr->next = nxt->next;
            nxt->next = prev->next;
            prev->next = nxt;
            nxt = curr->next;
        }
        l -= k;
        prev = curr;
    }
    return dummy->next;
}
