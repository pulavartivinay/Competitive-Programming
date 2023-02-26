Question:  https://leetcode.com/problems/find-the-duplicate-number/description/

Solution:

class Solution {
public:
    //if there is duplicate in the array, it means there is cycle in the array
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 0, f = 0;
        s = nums[s];
        f = nums[nums[f]];
        while(s != f)
        {
            s = nums[s];
            f = nums[nums[f]];
        }
        cout << s << " " << f << endl;
        f = 0;
        while(s != f)
        {
            s = nums[s];
            f = nums[f];
        }
        return s;
    }
};
