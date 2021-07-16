Question Link: https://practice.geeksforgeeks.org/problems/rearrange-a-linked-list/1#

Solution:

void rearrangeEvenOdd(Node *head)
{
   // Your Code here
   int odd[10000];
   int even[10000];
   Node* travel = head;
   int count = 1;
   int even_size = 0;
   int odd_size = 0;
   while(travel != NULL)
   {
       if(count & 1)
       {
           odd[odd_size] = travel->data;
           odd_size++;
       }
       else 
       {
           even[even_size] = travel->data;
           even_size++;
       }
       count++;
       travel = travel->next;
   }
  travel = head;
  int i = 0;
  while(i < odd_size)
  {
      travel->data = odd[i];
      i++;
      travel = travel->next;
  }
  int j=0;
  while(j < even_size)
  {
      travel->data = even[j];
      j++;
      travel = travel->next;
  }
}
