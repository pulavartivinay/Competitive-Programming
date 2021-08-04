Question Link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3838/

Solution:

void PreOrder(TreeNode* root,int sum,int targetSum,vector<int> temp,vector<vector<int>>& ans)
{
    if(root == NULL) return;

    sum += root->val;
    temp.push_back(root->val);
    // if(sum > targetSum) return;
    if(!root->left && !root->right && sum == targetSum) ans.push_back(temp);
    PreOrder(root->left,sum,targetSum,temp,ans);
    PreOrder(root->right,sum,targetSum,temp,ans);
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
{
    vector<vector<int>> ans;
    vector<int> temp;
    int sum = 0;
    PreOrder(root,sum,targetSum,temp,ans);
    vector<vector<int>> m;
    if(ans.size()>0 && ans[0].size() == 0) return m;
    return ans;
}
