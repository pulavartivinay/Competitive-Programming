Question Link: https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1#

Solution:

queue<int> modifyQueue(queue<int> q, int k) 
{
    // add code here.
    stack<int> s;
    for(int i=0;i<k;i++)
    {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    for(int i=k;i<q.size();i++)
    {
        q.push(q.front());
        q.pop();
    }
    return q;
}
