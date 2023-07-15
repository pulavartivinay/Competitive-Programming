Question Link: https://www.codingninjas.com/studio/problems/preorder-traversal_3838888?topList=striver-sde-sheet-problems&leftPanelTab=0

Solution:
void PreOrder(TreeNode* root, vector<int>& ans)
{
    TreeNode* curr = root;
    while(curr != NULL)
    {
        ans.push_back(curr->data);
        if(curr->left == NULL)
        {
            curr = curr->right;
        }
        else {
            TreeNode* prev1 = curr->left, *prev = curr->left;

            while(prev->right != NULL)
            {
                prev = prev->right;
            }

            prev->right = curr->right;
            curr->right = NULL;
            curr = prev1;
        }
    }
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    PreOrder(root, ans);
    return ans;
}
