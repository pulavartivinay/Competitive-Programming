Question Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

Solution:
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;

    queue<pair<TreeNode*, int>> q;
    q.push({root, 1});
    while(!q.empty())
    {
        pair<TreeNode*, int> p = q.front();
        TreeNode* curr_node = p.first;
        int curr_lvl = p.second;

        if(ans.size() < curr_lvl) ans.push_back({});

        if((curr_lvl & 1)) ans[curr_lvl-1].push_back(curr_node->val);
        else ans[curr_lvl-1].insert(ans[curr_lvl-1].begin(), curr_node->val);

        if(curr_node->left) q.push({curr_node->left, curr_lvl+1});
        if(curr_node->right) q.push({curr_node->right, curr_lvl+1});

        q.pop();
    }
    return ans;
}
