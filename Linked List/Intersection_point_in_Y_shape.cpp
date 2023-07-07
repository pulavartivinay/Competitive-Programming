Question Link: https://leetcode.com/problems/intersection-of-two-linked-lists/description/

Solution:
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int n = 0, m = 0;
    ListNode *t1 = headA, *t2 = headB;
    while(t1)
    {
        t1 = t1->next;
        n++;
    }
    while(t2)
    {
        t2 = t2->next;
        m++;
    }
    t1 = headA, t2 = headB;
    if(n > m)
    {
        int steps = (n - m);
        while(steps > 0)
        {
            t1 = t1->next;
            steps--;
        }
    } 
    else 
    {
        int steps = (m - n);
        while(steps > 0)
        {
            t2 = t2->next;
            steps--;
        }
    }
    
    while(t1 != t2)
    {
        t1 = t1->next;
        t2 = t2->next;
    }
    return t1;
}
