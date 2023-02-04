Question Link: https://leetcode.com/problems/next-permutation/description/

Solution:
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int b1 = 0;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i-1] < nums[i]) 
            {
                b1 = i-1;
                break;
            }
        }
        int b2 = 0;
        for(int i=n-1;i>b1;i--)
        {
            if(nums[i] > nums[b1]) 
            {
                b2 = i;
                break;
            }
        }
        //cout << b1 << " " << b2 << endl;
        swap(nums[b1], nums[b2]);
        if(b1 == 0 && b2 == 0) reverse(nums.begin(), nums.end());
        else reverse(nums.begin() + b1 + 1, nums.end());
    }
};
