Question: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

Solution:
static bool comp(pair<int,int> p1, pair<int,int> p2)
{
    if (p1.second < p2.second) return true;
    else if (p1.second > p2.second) return false; 
    else return (p1.first < p2.first);
}
//Function to find the maximum number of meetings that can
//be performed in a meeting room.
int maxMeetings(int start[], int end[], int n)
{
    // Your code here
    vector<pair<int,int>> intervals;
    for(int i=0;i<n;i++)
    {
        intervals.push_back({start[i], end[i]});
    }
    sort(intervals.begin(), intervals.end(), comp);
    
    int ans = 1;
    int newEnd = intervals[0].second;
    for(int i=1;i<n;i++)
    {
        if(newEnd < intervals[i].first)
        {
            newEnd = intervals[i].second;
            ans++;
        }
        else continue;
    }
    
    return ans;
}
