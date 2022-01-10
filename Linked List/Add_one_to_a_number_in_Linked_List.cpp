Question Link: https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1#

Solution:

Node* reverse(Node* head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* after;
    while(curr != NULL)
    {
        after = curr->next;
        curr->next = prev;

        prev = curr;
        curr = after;
    }
    return prev;
}
Node* addOne(Node *head) 
{
    // Your Code here
    // return head of list after adding one
    head = reverse(head);
    Node* t = head;
    Node* p = NULL;
    int carry = 1;
    while(t != NULL)
    {
        int a = (t->data + carry);
        t->data = a%10;
        carry = a/10;
        // cout << t->data << endl;
        p = t;
        t = t->next;
    }
    if(carry)
    {
        p->next = new Node(1);
    }
    head = reverse(head);
    return head;
}
