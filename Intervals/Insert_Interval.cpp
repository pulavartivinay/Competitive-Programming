Question Link: https://leetcode.com/problems/insert-interval/

Solution:

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
{
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    vector<vector<int>> ans;
    vector<int> curr = intervals[0];
    int i = 1;
    while(i < n)
    {
        if(curr[1] >= intervals[i][0])
        {
            curr[1] = max(curr[1], intervals[i][1]);
            i++;
        }
        else
        {
            ans.push_back(curr);
            curr = intervals[i];
            i++;
        }
    }
    ans.push_back(curr);
    return ans;
}
