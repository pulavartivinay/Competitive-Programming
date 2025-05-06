Question Link: https://leetcode.com/problems/build-array-from-permutation/description/

Solution:
vector<int> buildArray(vector<int>& nums) {
    int n = nums.size();

    // remainder --> original value
    // quotient --> final value
    for(int i=0;i<n;i++)
    {
        nums[i] += 1000 * (nums[nums[i]] % 1000);
    }

    for(int i=0;i<n;i++)
    {
        nums[i] = (nums[i] / 1000);
    }

    return nums;
}
