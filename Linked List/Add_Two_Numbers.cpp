Question Link: https://leetcode.com/problems/add-two-numbers/description/

Solution:
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode *ans = NULL, *curr = NULL;
    int sum = 0, val = 0, carry = 0;

    while(l1 && l2)
    {
        sum = (l1->val + l2->val + carry);
        val = (sum%10);
        carry = (sum/10);

        if(!ans)
        {
            curr = new ListNode(val);
            ans = curr;
        }
        else
        {
            curr->next = new ListNode(val);
            curr = curr->next;
        }
        l1 = l1->next;
        l2 = l2->next;
    }

    while(l1)
    {
        sum = (l1->val + carry);
        val = (sum%10);
        carry = (sum/10);

        if(!ans)
        {
            curr = new ListNode(val);
            ans = curr;
        }
        else
        {
            curr->next = new ListNode(val);
            curr = curr->next;
        }
        l1 = l1->next;
    }

    while(l2)
    {
        sum = (l2->val + carry);
        val = (sum%10);
        carry = (sum/10);

        if(!ans)
        {
            curr = new ListNode(val);
            ans = curr;
        }
        else
        {
            curr->next = new ListNode(val);
            curr = curr->next;
        }
        l2 = l2->next;
    }

    if(carry != 0) 
    {
        curr->next = new ListNode(carry);
        curr = curr->next;
    }

    return ans;
}
