Question Link: https://www.geeksforgeeks.org/problems/run-length-encoding/1

Solution:
string encode(string s) {
    // code here
    string ans = "";
    ans += s[0];
    char prev = s[0];
    int cnt = 1;
    int len = s.length();
    for(int i=1;i<len;i++)
    {
        if(s[i] != prev)
        {
            ans += to_string(cnt);
            cnt = 1;
            ans += s[i];
        }
        else cnt++;
        prev = s[i];
    }
    if(cnt != 0) ans += to_string(cnt);
    
    return ans;
}
