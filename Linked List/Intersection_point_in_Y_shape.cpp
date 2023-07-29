Question Link: https://leetcode.com/problems/intersection-of-two-linked-lists/description/

Solution:
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int n = 0, m = 0;
    ListNode *tA = headA, *tB = headB;
    while(tA || tB)
    {
        if(tA)
        {
            n++;
            tA = tA->next;
        }

        if(tB)
        {
            m++;
            tB = tB->next;
        }
    }

    int steps = abs(n-m);
    if(n >= m)
    {
        while(steps > 0 && headA)
        {
            headA = headA->next;
            steps--;
        }
    }
    else
    {
        while(steps > 0 && headB)
        {
            headB = headB->next;
            steps--;
        }
    }

    while(headA && headB && headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}
