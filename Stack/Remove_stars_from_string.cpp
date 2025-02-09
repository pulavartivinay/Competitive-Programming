Question Link: https://leetcode.com/problems/removing-stars-from-a-string/description/

Solution:
string removeStars(string s) {
    int n = s.length();
    stack<char> st;

    for(int i=0;i<n;i++)
    {
        if(s[i] == '*')
        {
            if(!st.empty()) st.pop();
        }
        else st.push(s[i]); 
    }

    string ans = "";
    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());

    return ans;
}
