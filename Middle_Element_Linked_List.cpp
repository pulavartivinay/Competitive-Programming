Question Link: https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1/?company[]=Amazon&company[]=Amazon&problemType=functional&page=1&sortBy=submissions&query=company[]AmazonproblemTypefunctionalpage1sortBysubmissionscompany[]Amazon

Solution:

int getMiddle(Node *head)
{
   // Your code here
   Node* travel = head;
   int count = 0;
   while(travel != NULL)
   {
       travel = travel->next;
       count = count + 1;
   }
   int point = (count/2);
   travel = head;
   while(point > 0)
   {
       travel = travel->next;
       point = point - 1;
   }
   return travel->data;
}
