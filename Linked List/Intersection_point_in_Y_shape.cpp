Question Link: https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1#

Solution Link:

int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    // visit all the nodes in one linked list
    unordered_map<Node*, int> li;
    Node* travel1 = head1;
    while(travel1 != NULL)
    {
        li[travel1] = 1;
        travel1 = travel1->next;
    }
    // now travel the other linked list and check whether it is visited or not
    // if it is visited, then return the curr node value
    // if there is no common Node in between, then return -1
    Node* travel2 = head2;
    while(travel2 != NULL)
    {
        if(li[travel2])
        {
            return travel2->data;
        }
        travel2 = travel2->next;
    }
    return -1;
}
