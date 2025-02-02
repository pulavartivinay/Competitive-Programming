Question Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

Solution:
bool check(vector<int>& nums) {
    int n = nums.size();

    for(int i=0;i<n;i++)
    {
        int j = i, cnt = 0;
        while(cnt < n-1)
        {
            if(nums[j % n] > nums[(j + 1) % n]) break;
            j++;
            cnt++;
        }

        if(cnt == n-1) return true;
    }

    return false;
}
