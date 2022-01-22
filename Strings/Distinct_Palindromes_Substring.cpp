Question Link: https://practice.geeksforgeeks.org/problems/distinct-palindromic-substrings5141/1

Solution:

int palindromeSubStrs(string s) 
{
    // code here
    int ans = 0;
    int n = s.length();
    unordered_set<string> st;
    for(int i=0;i<n;i++)
    {
        // even palindromes
        string temp = "";
        int left = i;
        int right = i+1;
        while(left >= 0 && right < n && s[left] == s[right])
        {
            temp = s[left] + temp + s[right];
            st.insert(temp);
            left--;
            right++;
        }


        // odd palindromes
        temp = s[i];
        st.insert(temp);
        left = i-1;
        right = i+1;
        while(left >= 0 && right < n && s[left] == s[right])
        {
            temp = s[left] + temp + s[right];
            st.insert(temp);
            left--;
            right++;
        }
    }
    ans = st.size();
    return ans;
}
