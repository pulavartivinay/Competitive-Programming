Question Link: https://practice.geeksforgeeks.org/problems/rearrange-characters4649/1#

Solution Link:

string rearrangeString(string str)
    {
        //code here
        string ans = "";
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> pq;
        int n = str.length();
        for(int i=0;i<n;i++)
        {
            m[str[i]] = m[str[i]] + 1;
        }
        string alpha_str = "abcdefghijklmnopqrstuvwxyz";
        for(int i=0;i<26;i++)
        {
            if(m[alpha_str[i]] > 0)
            {
                pq.push({m[alpha_str[i]], alpha_str[i]});
            }
        }
        pair<int, char> prev;
        prev.first = -1;
        prev.second = '#';
        while(!pq.empty())
        {
            pair<int, char> t;
            t = pq.top();
            pq.pop();
            ans += t.second;
            (t.first) = (t.first) -1;
            if(prev.first > 0)
            {
                pq.push(prev);
            }
            prev = t;
        }
        if(ans.length() == n)
        {
            return ans;
        }
        return "-1";
    }
    
