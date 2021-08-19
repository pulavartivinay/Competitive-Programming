Question Link: https://leetcode.com/problems/squares-of-a-sorted-array/

Solution:

vector<int> sortedSquares(vector<int>& nums) 
{
    int n = nums.size();
    vector<int> ans(n,0);
    int i = 0;
    int j = n-1;
    int pointer = n-1;
    while(i <= j)
    {
        if(pow(nums[i],2) > pow(nums[j],2))
        {
            ans[pointer] = pow(nums[i],2);
            i++;
        }
        else
        {
            ans[pointer] = pow(nums[j],2);
            j--;
        }
        pointer--;
    }
    return ans;
}
