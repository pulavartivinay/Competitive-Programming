Question Link: https://leetcode.com/problems/linked-list-random-node/\

Solution:

int length = 0;
vector<int> v;
Solution(ListNode* head) 
{
    ListNode* travel = head;
    while(travel != NULL)
    {
        length++;
        v.push_back(travel->val);
        travel = travel->next;
    }
}

int getRandom() 
{
    int a = rand()%length;
    return v[a];
}
