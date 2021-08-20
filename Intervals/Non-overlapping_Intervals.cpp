Question Link: https://leetcode.com/problems/non-overlapping-intervals/

Solution:

int eraseOverlapIntervals(vector<vector<int>>& intervals) 
{
    int n = intervals.size();
    sort(intervals.begin(),intervals.end());
    int ans = 0;
    int i = 1;
    int start = intervals[0][0];
    int end = intervals[0][1];
    while(i < n)
    {
        if(end > intervals[i][0])
        {
            ans++;
            end = min(end,intervals[i][1]);
        }
        else end = intervals[i][1];
        i++;
    }
    return ans;
}
