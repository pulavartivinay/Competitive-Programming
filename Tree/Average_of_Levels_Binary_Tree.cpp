Question Link: https://leetcode.com/problems/average-of-levels-in-binary-tree/

Solution:

vector<double> averageOfLevels(TreeNode* root) {
    vector<double> ans;
    queue<pair<TreeNode*,int>> q;
    q.push({root, 0});
    double s = 0.0;
    int level = 0;
    int count = 0;
    while(!q.empty())
    {
        auto b = q.front();
        if(b.first->left) q.push({b.first->left, b.second+1});
        if(b.first->right) q.push({b.first->right, b.second+1});
        if(b.second == level)
        {
            s += b.first->val;                
        }
        else
        {
            s = (s/count);
            ans.push_back(s);
            count = 0;
            level++;
            s = b.first->val;
        }
        count++;
        q.pop();
    }
    s = (s/count);
    ans.push_back(s);        
    return ans;
}
