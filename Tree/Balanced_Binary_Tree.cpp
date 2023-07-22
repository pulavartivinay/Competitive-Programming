Question Link: https://leetcode.com/problems/balanced-binary-tree/description/

Solution:
int getHeight(TreeNode* root, bool& ans)
{
    if(!ans) return 0;
    if(root)
    {
        int a = getHeight(root->left, ans);
        int b = getHeight(root->right, ans);
        if (abs(a - b) > 1) ans = false;
        return 1 + max(a,b);
    }
    return 0;
}
bool isBalanced(TreeNode* root) {
    if(!root) return true;
    bool ans = true;
    getHeight(root, ans);
    return ans;
}
