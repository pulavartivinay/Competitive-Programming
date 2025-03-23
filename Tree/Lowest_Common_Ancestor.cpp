Question Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

Solution:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     if(!root) return NULL;

     TreeNode *l = NULL, *r = NULL;
     l = lowestCommonAncestor(root->left, p, q);
     r = lowestCommonAncestor(root->right, p, q);
     if(root == p || root == q) return root;
     if(l && r) return root;
     if(l) return l;
     if(r) return r;
     return NULL;
 }
