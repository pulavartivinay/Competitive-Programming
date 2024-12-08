Question link: https://leetcode.com/problems/container-with-most-water/description/

Solution:
int maxArea(vector<int>& height) {
    int n = height.size();
    int ans = INT_MIN, area = INT_MIN;

    int low = 0, high = n-1;
    while(low < high)
    {
        area = min(height[low], height[high]) * (high - low);
        ans = max(ans, area);
        if(height[low] < height[high]) low++;
        else high--;
    }

    return ans;
}
