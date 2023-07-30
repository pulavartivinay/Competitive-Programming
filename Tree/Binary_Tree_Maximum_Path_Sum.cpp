Question Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

Solution:
int helper(TreeNode* root, int& ans)
{
    if(root)
    {
        int a = helper(root->left, ans);
        int b = helper(root->right, ans);
        ans = max(ans, max(a, b));
        a = (a == INT_MIN) ? 0 : a;
        b = (b == INT_MIN) ? 0 : b; 
        ans = max(ans, a + root->val + b);
        int c = max(a + root->val, b + root->val);
        ans = max(ans, max(c, root->val));

        return max(root->val, c);
    }
    else return INT_MIN;
}
int maxPathSum(TreeNode* root) {
    if(!root) return 0;
    int ans = INT_MIN;
    helper(root, ans);
    return ans;
}
