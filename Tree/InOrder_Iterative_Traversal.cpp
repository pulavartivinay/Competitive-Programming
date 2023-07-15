Question Link: https://leetcode.com/problems/binary-tree-inorder-traversal/description/

Solution:
void InOrder(TreeNode* root, vector<int>& ans)
{
    TreeNode* curr = root;
    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        } else {
            TreeNode* prev1 = curr->left, *prev = curr->left;

            while(prev->right != NULL)
            {
                prev = prev->right;
            }

            curr->left = NULL;
            prev->right = curr;
            curr = prev1;
        }
    }
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    InOrder(root, ans);
    return ans;
}
