Question: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

Solution:
int maxMeetings(int start[], int end[], int n)
{
    // Your code here
    int ans = 1;
    vector<pair<int,int>> store;
    for(int i=0;i<n;i++)
    {
        store.push_back({end[i], start[i]});
    }
    sort(store.begin(), store.end());
    int end_time = store[0].first;
    for(int i=1;i<n;i++)
    {
        if(store[i].second > end_time)
        {
            ans++;
            end_time = store[i].first;
        }
    }
    return ans;
}
