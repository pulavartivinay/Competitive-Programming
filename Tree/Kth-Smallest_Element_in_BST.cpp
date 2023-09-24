Question Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

Solution Link:
void inorder(TreeNode* root, int& k, int &ans)
{
    if(root)
    {
        inorder(root->left, k, ans);
        if(k == 1) 
        {
            ans = root->val;
            k--;
            return;
        }
        k--;
        inorder(root->right, k, ans);
    }
    return;
}

int kthSmallest(TreeNode* root, int k) 
{
    if(root)
    {
        int ans = -1;
        inorder(root, k, ans);
        return ans;
    }
    return -1;
}
