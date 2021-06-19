Question Link: https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1

Solution:

void InOrder(Node* root, priority_queue<int>& pq)
{
    if(root)
    {
        InOrder(root->left, pq);
        pq.push(-1* root->data);
        InOrder(root->right, pq);
    }
}
vector<int> merge(Node *root1, Node *root2)
{
   //Your code here
   priority_queue<int> pq;
   InOrder(root1, pq);
   InOrder(root2, pq);
   vector<int> ans;
   while(!pq.empty())
   {
       ans.push_back(-1 * pq.top());
       pq.pop();
   }
   return ans;
}
