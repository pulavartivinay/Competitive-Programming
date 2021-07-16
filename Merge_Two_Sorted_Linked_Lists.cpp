Question Link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1#

Solution:

Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    Node* travel1 = head1;
    Node* travel2 = head2;
    Node* curr = NULL;
    if(travel1->data < travel2->data) 
    {
        curr = new Node(travel1->data);
        travel1 = travel1->next;
    }
    else 
    {
        curr = new Node(travel2->data);
        travel2 = travel2->next;
    }
    Node* ans = curr;
    while(travel1 != NULL && travel2 != NULL)
    {
        if(travel1->data < travel2->data)
        {
            Node* t = new Node(travel1->data);
            travel1 = travel1->next;
            curr->next = t;
            curr = curr->next;
        }
        else
        {
            Node* t = new Node(travel2->data);
            travel2 = travel2->next;
            curr->next = t;
            curr = curr->next;
        }
    }
    while(travel1 != NULL)
    {
        Node* t = new Node(travel1->data);
        travel1 = travel1->next;
        curr->next = t;
        curr = curr->next;
    }
    while(travel2 != NULL)
    {
        Node* t = new Node(travel2->data);
        travel2 = travel2->next;
        curr->next = t;
        curr = curr->next;
    }
    return ans;
}
