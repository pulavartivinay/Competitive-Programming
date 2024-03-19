Question Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

Solution:
vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;

    if(!root) return ans;

    unordered_map<int, unordered_map<int, vector<int>>> mp;
    int min_row = INT_MAX, max_row = INT_MIN;
    int min_col = INT_MAX, max_col = INT_MIN;
    queue<pair<TreeNode*, vector<int>>> q;
    q.push({root, {0,0}});

    while(!q.empty())
    {
        pair<TreeNode*, vector<int>> p = q.front();
        q.pop();
        TreeNode* curr = p.first;
        int row = p.second[0];
        int col = p.second[1];

        mp[row][col].push_back(curr->val);

        
        min_row = min(min_row, row);
        max_row = max(max_row, row);

        min_col = min(min_col, col);
        max_col = max(max_col, col);

        if(curr->left) q.push({curr->left, {row+1, col-1}});
        if(curr->right) q.push({curr->right, {row+1, col+1}});
    }

    for(int i=min_col; i<=max_col;i++)
    {
        vector<int> temp;
        for(int j=min_row; j<=max_row;j++)
        {
            if(mp[j][i].size() != 0)
            {
                sort(mp[j][i].begin(), mp[j][i].end());
                for(int k=0;k<mp[j][i].size();k++) temp.push_back(mp[j][i][k]);
            }
        }
        ans.push_back(temp);
    }

    return ans;
}
