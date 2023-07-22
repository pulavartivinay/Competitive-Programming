Question Link: https://leetcode.com/problems/diameter-of-binary-tree/description/

Solution:
int getHeight(TreeNode* root, int& ans)
{
    if(root)
    {
        int a = getHeight(root->left, ans);
        int b = getHeight(root->right, ans);
        ans = max(ans, 1 + a + b);
        return 1 + max(a,b);
    }
    return 0;
}
int diameterOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    int ans = 1;
    getHeight(root, ans);
    return ans-1;
}
