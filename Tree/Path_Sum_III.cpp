Question Link: https://leetcode.com/problems/path-sum-iii/description/

Solution:
void helper(TreeNode* root, int targetSum, vector<long long int> v, int& ans)
{
    if(!root) return;

    for(int i=0;i<v.size();i++)
    {
        v[i] += root->val;
        if(v[i] == targetSum)
        {
            cout << root->val << endl;
            ans++;
        }
    }

    if(root->val == targetSum) ans++;

    v.push_back(root->val);
    helper(root->left, targetSum, v, ans);
    helper(root->right, targetSum, v, ans);

}
int pathSum(TreeNode* root, int targetSum) {
    vector<long long int> v;
    int ans = 0;
    helper(root, targetSum, v, ans);

    return ans;
}
