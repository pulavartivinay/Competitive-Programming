Question Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/

Solution:
void helper(TreeNode* root, int m, int& ans)
{
    if(!root) return;

    if(root->val >= m) ans++;
    helper(root->left, max(m, root->val), ans);
    helper(root->right, max(m, root->val), ans);
}
int goodNodes(TreeNode* root) {
    int ans = 0, max_so_far = INT_MIN;
    helper(root, max_so_far, ans);

    return ans;
}
