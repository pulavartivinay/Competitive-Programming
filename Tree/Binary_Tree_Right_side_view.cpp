Question Link: https://leetcode.com/problems/binary-tree-right-side-view/description/

Solution:
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;

    queue<pair<TreeNode*, int>> q;
    q.push({root, 1});

    while(!q.empty())
    {
        pair<TreeNode*, int> p = q.front();
        q.pop();

        TreeNode* node = p.first;
        int lvl = p.second;

        if(lvl > ans.size()) ans.push_back(node->val);
        else ans[lvl-1] = node->val;

        if(node->left) q.push({node->left, lvl+1});
        if(node->right) q.push({node->right, lvl+1});
    }

    return ans;
}
