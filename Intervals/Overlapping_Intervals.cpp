Question Link: https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1

Solution:

vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) 
{
    vector<vector<int>>ans;
    if(intervals.size() == 0)
        return ans;
    sort(intervals.begin(), intervals.end());
    int l = intervals[0][0];
    int r = intervals[0][1];
    for(int i = 1; i < intervals.size(); i++){
        if(intervals[i][0] <= r)
            r = max(r, intervals[i][1]);
        else{
            ans.push_back({l,r});
            l = intervals[i][0];
            r = intervals[i][1];
        }
    }
    ans.push_back({l,r});
    return ans;
}
