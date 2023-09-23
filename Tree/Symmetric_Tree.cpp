Question Link: https://leetcode.com/problems/symmetric-tree/

Solution:
bool isSymmetricHelper(TreeNode*root1, TreeNode* root2) 
{
    if(!root1 && !root2) return true;
    if(!root1 || !root2) return false;
    if(root1->val != root2->val) return false;
    return (isSymmetricHelper(root1->left, root2->right) & isSymmetricHelper(root1->right, root2->left));
}

bool isSymmetric(TreeNode* root) 
{
    if(!root->left && !root->right) return true;
    if(!root->left || !root->right) return false;
    return isSymmetricHelper(root->left, root->right);
}
