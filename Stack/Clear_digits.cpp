Question Link: https://leetcode.com/problems/clear-digits/description/

Solution:
string clearDigits(string s) {
    int n = s.length();
    string ans = "";
    stack<char> st;

    for(int i=0;i<n;i++)
    {
        if(0 <= s[i]-'0' && s[i]-'0' <= 9)
        {
            if(!st.empty()) st.pop();
        }
        else st.push(s[i]);
    }

    while(!st.empty())
    {
        ans = st.top() + ans;
        st.pop();
    }

    return ans;
}
