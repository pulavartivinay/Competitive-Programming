Question Link: https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

Solution:

Node* divide(int N, Node *head)
{
    // code here
    Node* travel = head;
    queue<int> even,odd;
    while(travel != NULL)
    {
        if(travel->data & 1) odd.push(travel->data);
        else even.push(travel->data);
        travel = travel->next;
    }
    travel = head;
    while(!even.empty())
    {
        travel->data = even.front();
        even.pop();
        travel = travel->next;
    }
    while(!odd.empty())
    {
        travel->data = odd.front();
        odd.pop();
        travel = travel->next;
    }
    return head;
}
