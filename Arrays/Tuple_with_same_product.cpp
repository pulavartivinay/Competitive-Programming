Question Link: https://leetcode.com/problems/tuple-with-same-product/description/

Solution:
int tupleSameProduct(vector<int>& nums) {
    int n = nums.size();
    int ans = 0, prod = 1;

    unordered_map<int, int> mp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            prod = nums[i] * nums[j];
            ans = ans + (mp[prod] * 8);
            mp[prod]++;
        }
    }

    return ans;
}
