Question Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

Solution:
int findMinArrowShots(vector<vector<int>>& points) {
    int ans = 1, n = points.size();
    sort(points.begin(), points.end());

    int start = points[0][0], end = points[0][1];
    for(int i=1;i<n;i++)
    {
        if(end < points[i][0])
        {
            ans++;
            start = points[i][0];
            end = points[i][1];
        }
        else
        {
            start = max(start, points[i][0]);
            end = min(end, points[i][1]);
        }
    }

    return ans;
}
