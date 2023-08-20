Question Link: https://leetcode.com/problems/4sum/description/

Solution:
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    set<vector<int>> t_ans;

    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int a=0;a<n;a++)
    {
        for(int b=a+1;b<n;b++)
        {
            int low = b+1, high = n-1;
            while(low < high)
            {
                long long int s = nums[a];
                s += nums[b];
                s += nums[low];
                s += nums[high];
                if(s == target)
                {
                    t_ans.insert({nums[a], nums[b], nums[low], nums[high]});
                    low++;
                    high--;
                }
                else if(s < target) low++;
                else high--;
            }
        }
    }
    vector<vector<int>> ans(t_ans.begin(), t_ans.end());
    return ans;
}
