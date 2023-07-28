Question Link: https://leetcode.com/problems/reverse-words-in-a-string/description/

Solution:
string reverseWords(string s) {
    int n = s.length();
    string temp = "";
    string ans = "";
    for(int i=0;i<n;i++)
    {
        if(s[i] != ' ') temp += s[i];
        else
        {
            if(temp != "") 
            {
                if(ans != "") ans = temp + " " + ans;
                else ans = temp;
            }
            temp = "";
        }
    }
    if(temp != "") 
    {
        if (ans != "") ans = temp + " " + ans;
        else ans = temp;
    }

    return ans;
}
