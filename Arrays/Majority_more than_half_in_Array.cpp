Question Link: https://leetcode.com/problems/majority-element/description/

Solution:
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int count = 1, ele = nums[0];
    for(int i=1;i<n;i++)
    {
        if(count == 0) ele = nums[i];
        
        if(ele != nums[i]) count--;
        else count++;
    }

    return ele;
}
