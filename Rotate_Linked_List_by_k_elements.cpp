Question Link: https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1

Solution Link: 

Node* rotate(Node* head, int k)
    {
        // Your code here
        Node* front = head;
        Node* last = head;
        while(last->next != NULL)
        {
            last = last->next;
        }
        while(k > 0)
        {
            Node* after = front->next;
            front->next = NULL;
            
            last->next = front;
            last = last->next;
            
            front = after;
            k = k - 1;
        }
        return front;
    }
