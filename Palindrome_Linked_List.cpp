Question Link: https://leetcode.com/problems/palindrome-linked-list/

Solution:

bool isPalindrome(ListNode* head) 
{
    string li = "";
    ListNode* travel = head;
    while(travel != NULL)
    {
        li += travel->val;
        travel = travel->next;
    }
    string hi = li;
    reverse(hi.begin(),hi.end());
    if(hi == li) return 1;
    else return 0;
}
