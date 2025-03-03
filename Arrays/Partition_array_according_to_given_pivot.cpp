Question Link: https://leetcode.com/problems/partition-array-according-to-given-pivot/description/

Solution:
vector<int> pivotArray(vector<int>& nums, int pivot) {
    int n = nums.size();
    vector<int> ans(n, pivot);

    int left = 0, right = n-1;
    int i = 0, j = n-1;
    while(i < n && j >= 0)
    {
        if(nums[i] < pivot)
        {
            ans[left] = nums[i];
            left++;
        }

        if(nums[j] > pivot)
        {
            ans[right] = nums[j];
            right--;
        }
        i++;
        j--;
    }

    return ans;
}
