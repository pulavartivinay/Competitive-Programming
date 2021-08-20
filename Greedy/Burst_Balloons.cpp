Question Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

Solution:

int findMinArrowShots(vector<vector<int>>& points) 
{
    int n = points.size();
    sort(points.begin(),points.end());
    int ans = 1;
    int start = points[0][0];
    int end = points[0][1];
    for(int i=1;i<n;i++)
    {
        if(end >= points[i][0])
        {
            end = min(end,points[i][1]);
        }
        else
        {
            ans++;
            end = points[i][1];
        }
    }
    return ans;
}
