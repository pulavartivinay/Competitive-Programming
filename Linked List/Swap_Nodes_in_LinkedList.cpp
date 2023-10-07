Question Link: https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1

Solution:
Node* pairWiseSwap(struct Node* head) 
{
    // The task is to complete this method
    struct Node *nxt = NULL, *tmp = NULL;
    if(head && head->next) 
    {
        nxt = pairWiseSwap(head->next->next);
        tmp = head->next;
        head->next = nxt;
        tmp->next = head;
        head = tmp;
    }
    
    return head;
}
