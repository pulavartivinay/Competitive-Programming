Question Link: https://leetcode.com/problems/find-all-duplicates-in-an-array/

Solution:

vector<int> findDuplicates(vector<int>& nums) 
{
    vector<int> ans;
    int n = nums.size();
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-1;i++)
    {
        if(nums[i] == nums[i+1]) ans.push_back(nums[i]);
    }
    return ans;
}
