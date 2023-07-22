Question Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

Solution:
int maxDepth(TreeNode* root) {
    if(!root) return 0;
    else return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
