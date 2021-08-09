Question Link: https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1

Solution:

void deleteNode(Node *del)
{
   // Your code here
   Node* travel = del;
   while(travel->next->next != NULL)
   {
       Node* after = travel->next;
       travel->data = after->data;
       travel = travel->next;
   }
   Node* after = travel->next;
   travel->data = after->data;
   travel->next = NULL;
}
