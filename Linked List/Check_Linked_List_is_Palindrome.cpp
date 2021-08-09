Question Link: https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

Solution:

bool isPalindrome(Node *head)
{
    //Your code here
    string s;
    Node* travel = head;
    while(travel != NULL)
    {
        s += to_string(travel->data);
        travel = travel->next;
    }
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
    string li;
    travel = prev;
    while(travel != NULL)
    {
        li += to_string(travel->data);
        travel = travel->next;
    }
    if(s == li) return 1;
    else return 0;
}
