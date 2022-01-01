Question Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/

Solution:

void dep(TreeNode* root, int h, int &ans)
{
    if(root)
    {
        if(!root->left && !root->right) 
        {
            if(h < ans) ans = h;
            return;
        }
        else
        {
            if(root->left) dep(root->left, h+1, ans);
            if(root->right) dep(root->right, h+1, ans);
        }
    }
    return;
}
int minDepth(TreeNode* root) {
    if(!root) return 0;
    int ans = INT_MAX;
    int h = 1;
    dep(root, h, ans);
    return ans;
}
