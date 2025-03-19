Question Link: https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/

Solution:
// If nums[0] is 0, then the only way to change it to 1 is
// by doing an operation on the first 3 elements of the array.
int minOperations(vector<int>& nums)
{
    int n = nums.size();
    int ans = 0;

    int i = 0;
    for(i=0;i<(n-2);i++)
    {
        if(nums[i]) continue;
        // flip i, i+1, i+2 positions
        nums[i] = !nums[i];
        nums[i+1] = !nums[i+1];
        nums[i+2] = !nums[i+2];
        ans++;
    }

    while(i < n)
    {
        if(nums[i] == 0) return -1;
        i++;
    }

    return ans;
}
