Question: https://leetcode.com/problems/subsets-ii/description/

Solution:

class Solution {
public:
void recur(int a, int b, vector<int> temp_v, vector<int> nums, set<vector<int>>& s)
{
    if(a < b)
    {
        //element is not present
        recur(a+1,b,temp_v,nums,s);
        //element is present
        temp_v.push_back(nums[a]);
        recur(a+1,b,temp_v,nums,s);
    }
    else s.insert(temp_v);
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    set<vector<int>> s;
    vector<int> temp_v;
    recur(0,n,temp_v,nums,s);
    vector<vector<int>> ans(s.begin(), s.end());
    sort(ans.begin(), ans.end());
    return ans;
}
};
