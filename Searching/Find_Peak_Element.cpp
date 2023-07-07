Question Link: https://leetcode.com/problems/find-peak-element/description/

Solution:
int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int start = 0, end = n-1;
    while(start < end) {
        int mid = start + ((end - start)/2);
        if(nums[mid] < nums[mid+1]) start = mid+1;
        else end = mid;
    }
    return start;
}
