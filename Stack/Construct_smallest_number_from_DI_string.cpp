Question Link: https://leetcode.com/problems/construct-smallest-number-from-di-string/description/

Solution:
string smallestNumber(string pattern) {
    int n = pattern.length();
    stack<char> st;
    string ans = "";

    for(int i=0;i<n;i++)
    {
        if(pattern[i] == 'I')
        {
            while(!st.empty())
            {
                ans += st.top();
                st.pop();
            }

            if(ans == "")
            {    
                ans += to_string(i+1);
                ans += to_string(i+2);
            }
            else ans += to_string(i+2);
        }
        else
        {
            if(st.empty())
            {
                if(ans != "") ans.pop_back();
                st.push(i+1 + '0');
                st.push(i+2 + '0');
            }
            else st.push(i+2 + '0');
        }
    }

    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}
