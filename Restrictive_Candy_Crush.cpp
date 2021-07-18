Question Link: https://practice.geeksforgeeks.org/problems/8c8f95810b05b4cab665f2997d36991bd58308a2/1/

Solution:

string Reduced_String(int k,string str){
    // Your code goes here
    if(k == 1) return "";
    string ans = "";
    stack<pair<char,int> > s;
    int n = str.length();
    int i = 0;
    while(i < n)
    {
        if(!s.empty())
        {
            if(s.top().second == k)
            {
                s.pop();
            }
            else
            {
                if(s.top().first == str[i])
                {
                    pair<char, int> p = s.top();
                    s.pop();
                    s.push({p.first, p.second+1});
                    i++;
                }
                else
                {
                    s.push({str[i],1});
                    i++;
                }
            }
        }
        else
        {
            s.push({str[i],1});
            i++;
        }
    }
    if(s.top().second == k)
    {
        s.pop();
    }
    string li = "";
    while(!s.empty())
    {
        string li ( s.top().second, s.top().first);
        ans += li;
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
