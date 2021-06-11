Question Link: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

Solution Link:

struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        Node* before = NULL;
        Node* current = head;
        Node* after = NULL;
        while(current != NULL)
        {
            after = current->next;
            current->next = before;
            
            before = current;
            current = after;
        }
        return before;
    }
