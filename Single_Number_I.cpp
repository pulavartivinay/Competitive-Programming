Question Link: https://leetcode.com/problems/single-number/

Solution:

int singleNumber(vector<int>& nums) 
{
    int ans = 0;
    int n = nums.size();
    // just simple concept : XOR of same elemnts will result in zero and XOR with zero will return the same input.
    // (A^A = 0 and A^0 = A)in mathematical terms
    for(int i=0;i<n;i++)
    {
        ans = ans ^ nums[i];
    }
    return ans;
}
