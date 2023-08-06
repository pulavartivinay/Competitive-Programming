Question Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

Solution:
TreeNode* insertBST(TreeNode* ans, int val)
{
    if(!ans) return new TreeNode(val);
    if(val < ans->val) ans->left = insertBST(ans->left, val);
    else ans->right = insertBST(ans->right, val);
    return ans;
}

TreeNode* insertHelperBST(vector<int>& nums, int start, int end, TreeNode* ans)
{
    if(start > end) return ans;

    int mid = start + ((end - start)/2);
    ans = insertBST(ans, nums[mid]);
    ans = insertHelperBST(nums, start, mid-1, ans);
    ans = insertHelperBST(nums, mid+1, end, ans);

    return ans;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    int n = nums.size();
    TreeNode* ans = NULL;
    ans = insertHelperBST(nums, 0, n-1, ans);
    return ans;
}
