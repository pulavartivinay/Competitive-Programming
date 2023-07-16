Question Link: https://leetcode.com/problems/maximum-width-of-binary-tree/description/

Solution:
int widthOfBinaryTree(TreeNode* root) {
    long long int ans = 0;
    long long int start_width = 0, end_width = 0;
    long long int prev_lvl = 0;

    queue<pair<TreeNode*,vector<long long int>>> q;
    q.push({root, {1, 0}});
    while(!q.empty())
    {
        pair<TreeNode*,vector<long long int>> p = q.front();
        TreeNode* curr_node = p.first;
        vector<long long int> v = p.second;
        long long int curr_lvl = v[0];
        long long int index = v[1];

        if(curr_lvl != prev_lvl) 
        {
            prev_lvl = curr_lvl;

            //cout << "start: " << start_width << "end: " << end_width << endl;

            ans = max(ans, end_width - start_width + 1);
            start_width = index;
        }

        end_width = index;

        if(curr_node->left) q.push({curr_node->left, {curr_lvl+1, 2*(index-start_width)+1}});
        if(curr_node->right) q.push({curr_node->right, {curr_lvl+1, 2*(index-start_width)+2}});

        q.pop();
    }
    //cout << "start: " << start_width << "end: " << end_width << endl;
    ans = max(ans, end_width - start_width + 1);
    return ans;
}
