Question Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

Solution:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return root;

    int a = min(p->val,q->val);
    int b = max(p->val,q->val);
    if(a <= root->val && root->val <= b) return root;
    else if(b < root->val) return lowestCommonAncestor(root->left, p , q);
    else return lowestCommonAncestor(root->right, p, q);
}
