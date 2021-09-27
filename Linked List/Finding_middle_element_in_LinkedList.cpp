Question Link: https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

Solution:

int getMiddle(Node *head)
  {
      // Your code here
      int count = 0;
      Node* t = head;
      while(t != NULL)
      {
          count++;
          t = t->next;
      }
      t = head;
      for(int i=0;i<(count/2);i++)
      {
          t = t->next;
      }
      return t->data;
  }
