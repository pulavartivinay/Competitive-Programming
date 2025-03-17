Question Link: https://leetcode.com/problems/divide-array-into-equal-pairs/description/

Solution:
bool divideArray(vector<int>& nums)
{
    int n = nums.size();
    unordered_map<int, int> mp;

    for(int i=0;i<n;i++)
    {
        mp[nums[i]]++;
    }

    for(auto k:mp)
    {
        if(k.second & 1) return false;
    }

    return true;
}
