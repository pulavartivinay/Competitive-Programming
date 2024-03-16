Question Link: https://www.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1

Solution:
void sort(Node **head)
{
   // Code here
   int n = 1;
   Node* last = *head;
   while(last->next) {
       last = last->next;
       n++;
   }
   
   if(n <= 2) return;
   
   Node* curr = *head, *last_end = NULL;
   for(int i=0;i<(n/2);i++)
   {
       if(curr && curr->next)
       {
           Node* temp = curr->next;
           curr->next = temp->next;
           temp->next = NULL;
           last->next = temp;
           last_end = curr;
           last = last->next;
           curr = curr->next;
       }
   }
   
   if(n & 1)
   {
       last_end = curr;
       curr = curr->next;
   }
   
   Node* prev = NULL;
   while(curr)
   {
       Node* nxt = curr->next;
       curr->next = prev;
       prev = curr;
       curr = nxt;
   }
   
   last_end->next = prev;
}
