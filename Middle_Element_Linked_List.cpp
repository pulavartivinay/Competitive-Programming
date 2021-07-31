Question Link: https://leetcode.com/problems/middle-of-the-linked-list/

Solution:

ListNode* middleNode(ListNode* head) 
{
  ListNode* slow = NULL;
  ListNode* fast = NULL;
  if(head)
  {
      slow = head;
      fast = head;
  }
  else return NULL;
  while(fast != NULL && fast->next != NULL)
  {
      slow = slow->next;
      fast = fast->next->next;
  }
  return slow;
}
