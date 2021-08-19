Question Link: https://leetcode.com/problems/backspace-string-compare/

Solution:

bool backspaceCompare(string s, string t) 
{
    int n = s.length();
    stack<char> st;
    for(int i=0;i<n;i++)
    {
        if(s[i] != '#') st.push(s[i]);
        else 
        {
            if(!st.empty()) st.pop();
        }
    }
    s = "";
    while(!st.empty())
    {
        s += st.top();
        st.pop();
    }

    int m = t.length();
    for(int i=0;i<m;i++)
    {
        if(t[i] != '#') st.push(t[i]);
        else 
        {
            if(!st.empty()) st.pop();
        }
    }
    t = "";
    while(!st.empty())
    {
        t += st.top();
        st.pop();
    }
    return (s == t);
}
