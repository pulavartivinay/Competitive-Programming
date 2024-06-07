Question Link: https://leetcode.com/problems/subarray-product-less-than-k/description/?envType=problem-list-v2&envId=xlem03mm

Solution:
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int n = nums.size();
    int i=0, j=0;
    int ans = 0, curr_prod = 1;

    while(j < n)
    {
        curr_prod = curr_prod * nums[j];
        while(i <= j && curr_prod >= k) 
        {
            curr_prod = (curr_prod/nums[i]);
            i++;
        }
        ans += (j-i+1);
        j++;
    }

    return ans;
}
