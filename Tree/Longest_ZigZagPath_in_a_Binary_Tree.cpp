Question Link: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/

Solution:
class Solution {
public:
    int ans = 0;
    void helper(TreeNode* root, int dir, int steps)
    {
        if(!root) return;

        ans = max(ans, steps);

        // left direction
        if(dir == 0)
        {
            helper(root->left, !dir, steps+1);
            helper(root->right, dir, 1);
        }
        // right direction
        else
        {
            helper(root->right, !dir, steps+1);
            helper(root->left, dir, 1);
        }
    }
    int longestZigZag(TreeNode* root) {
        helper(root, 0, 0);

        return ans;
    }
};
