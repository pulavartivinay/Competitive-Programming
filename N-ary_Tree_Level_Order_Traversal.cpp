Question Link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3871/

Solution:

vector<vector<int>> levelOrder(Node* root) 
{
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    deque<Node*> q1;
    deque<Node*> q2;
    q1.push_back(root);
    ans.push_back({root->val});
    while(!q1.empty())
    {
        Node* j = q1.front();
        for(int i=0;i<(j->children.size());i++)
        {
            q2.push_back(j->children[i]);
        }
        q1.pop_front();
        if(q1.empty())
        {
            vector<Node*> b(q2.begin(),q2.end());
            vector<int> c;
            for(int k=0;k<b.size();k++)
            {
                c.push_back(b[k]->val);
            }
            if(c.size() > 0) ans.push_back(c);
            swap(q1,q2);
        }
    }
    return ans;
}
