Question Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

Solution:
TreeNode* insertBST(TreeNode* ans, int val)
{
    if(ans)
    {
        if(val < ans->val) ans->left = insertBST(ans->left, val);
        else ans->right = insertBST(ans->right, val);

        return ans;
    }
    else return new TreeNode(val);
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int n = preorder.size();
    TreeNode* ans = NULL;
    if(n == 0) return ans;

    for(int i=0;i<n;i++)
    {
        ans = insertBST(ans, preorder[i]);
    }
    return ans;
}
