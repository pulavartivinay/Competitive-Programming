Question Link: https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/

Solution:
int getMinOps(vector<int>& arr, int n)
{
    int cnt = 0;
    unordered_map<int,int> mp;
    vector<int> temp(arr.begin(), arr.end());

    for(int i=0;i<n;i++) mp[arr[i]] = i;

    sort(temp.begin(), temp.end());

    for(int i=0;i<n;i++)
    {
        if(arr[i] != temp[i])
        {
            int idx = mp[temp[i]];
            mp[arr[i]] = idx;
            swap(arr[i], arr[idx]);
            cnt++;
        }
    }

    return cnt;
}
int minimumOperations(TreeNode* root) {
    if(!root) return 0;
    int ans = 0;

    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        vector<int> arr;
        int curr_lvl_size = q.size();

        for(int i=0;i<curr_lvl_size;i++)
        {
            TreeNode* node = q.front();
            q.pop();
            arr.push_back(node->val);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        ans += getMinOps(arr, curr_lvl_size);
    }

    return ans;
}
