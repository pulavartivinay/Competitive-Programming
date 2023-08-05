Question Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

Solution:
TreeNode* findPorQ(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root)
    {
        TreeNode* a = findPorQ(root->left, p, q);
        TreeNode* b = findPorQ(root->right, p, q);

        if(a && b) return root;
        else if(root->val == p->val | root->val == q->val) return root;
        else return (a ? a : b);
    }
    else return NULL;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return NULL;
    return findPorQ(root, p, q);
}
