Question Link: https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

Solution:
Node * removeDuplicates( Node *head) 
{
 // your code goes here
 unordered_map<int,int> m;
 Node *prev = NULL, *tr = head;
 while(tr)
 {
     m[tr->data]++;
     // duplicate case
     if(m[tr->data] > 1)
     {
         prev->next = tr->next;
         tr = prev->next;
     }
     else
     {
         prev = tr;
         tr = tr->next;
     }
 }
 return head;
}
