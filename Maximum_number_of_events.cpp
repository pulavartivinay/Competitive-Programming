Question Link: https://practice.geeksforgeeks.org/contest/interview-series-adobe/problems/

Solution:

int maxEvents(int start[], int end[], int N) {
    // code here
    vector<pair<int,int>> ranges;
    for(int i=0;i<N;i++)
    {
        ranges.push_back({start[i],end[i]});
    }
    sort(ranges.begin(), ranges.end());

    int ans = 0;
    int i=0;
    multiset<int> s;
    for(int day=1;day<=100000;day++)
    {
        // 1. add all segments whose starting times are equal with curent day
        while(i < N && ranges[i].first == day)
        {
            s.insert(ranges[i].second);
            i = i + 1;
        }
        // 2. remove the invalid segments in the set
        while(!s.empty() && *s.begin() < day)
        {
            s.erase(s.begin());
        }
        // 3. assign the day to with least ending day
        if(!s.empty())
        {
            ans = ans + 1;
            s.erase(s.begin());
        }
    }
    return ans;
}
