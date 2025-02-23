Question Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/

Solution:
int maxLevelSum(TreeNode* root) {
    int sum = INT_MIN, curr_sum = 0, ans = 0, lvl = 1;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 1});

    while(!q.empty())
    {
        pair<TreeNode*, int> p = q.front();
        q.pop();

        TreeNode* node = p.first;
        int curr_lvl = p.second;

        if(curr_lvl != lvl)
        {
            if(curr_sum > sum)
            {
                sum = curr_sum;
                ans = lvl;
            }
            lvl = curr_lvl;
            curr_sum = 0;
        }
        curr_sum += node->val;

        if(node->left) q.push({node->left, curr_lvl+1});
        if(node->right) q.push({node->right, curr_lvl+1});
    }

    if(curr_sum > sum)
    {
        sum = curr_sum;
        ans = lvl;
    }

    return ans;
}
