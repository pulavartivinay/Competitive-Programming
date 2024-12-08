Question Link: https://leetcode.com/problems/two-best-non-overlapping-events/description/

Solution:
int maxTwoEvents(vector<vector<int>>& events) {
    int n = events.size(), ans = INT_MIN;
    sort(events.begin(), events.end());

    vector<int> suffixMax(n, 0);
    suffixMax[n-1] = events[n-1][2];
    for(int i=n-2;i>=0;i--)
    {
        suffixMax[i] = max(events[i][2], suffixMax[i+1]); 
    }

    int low = 0, high = 0, ind = -1;

    for(int i=0;i<n;i++)
    {
        low = i+1, high = n-1, ind = -1;
        while(low <= high)
        {
            int mid = (low + (high - low)/2);
            if(events[i][1] < events[mid][0])
            {
                high = mid-1;
                ind = mid;
            }
            else low = mid+1;
        }

        if(ind != -1)
        {
            ans = max(ans, events[i][2] + suffixMax[ind]);
        }
        else ans = max(ans, events[i][2]);
    }

    return ans;
}
