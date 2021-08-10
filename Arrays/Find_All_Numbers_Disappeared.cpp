Question Link: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

Solution:

vector<int> findDisappearedNumbers(vector<int>& nums) 
{
    vector<int> ans;
    int n = nums.size();
    vector<bool> v (n,0);
    for(int i=0;i<n;i++)
    {
        v[nums[i]] = 1;
    }
    for(int i=1;i<=n;i++)
    {
        if(v[i] == 0) ans.push_back(i);
    }
    return ans;
}
