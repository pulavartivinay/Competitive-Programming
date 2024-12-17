Question Link: https://leetcode.com/problems/construct-string-with-repeat-limit/description/

Solution:
struct comp
{
    bool operator()(pair<char,int> p1, pair<char,int> p2)
    {
        return (p1.first <= p2.first);
    }
};
string repeatLimitedString(string s, int repeatLimit) {
    string ans = "";
    int n = s.length();
    vector<int> count(26, 0);
    priority_queue< pair<char,int>, vector<pair<char,int>>, comp> pq;

    for(int i=0;i<n;i++)
    {
        int idx = s[i]-'a';
        count[idx]++;
    }

    char c = 'a';
    for(int i=0;i<26;i++) if(count[i] > 0) pq.push({c+i, count[i]});

    while(!pq.empty())
    {
        pair<char,int> p1 = pq.top();
        pq.pop();

        char c1 = p1.first;
        int cnt1 = p1.second;

        if(cnt1 <= repeatLimit) for(int i=0;i<cnt1;i++) ans += c1;
        else
        {
            for(int i=0;i<repeatLimit;i++) ans += c1;
            if(pq.empty()) break;
                
            pair<char,int> p2 = pq.top();
            pq.pop();

            char c2 = p2.first;
            int cnt2 = p2.second;

            ans += c2;
            if (cnt2-1 > 0) pq.push({c2, cnt2-1});

            pq.push({c1, cnt1 - repeatLimit});
        }
    }

    return ans;
}
