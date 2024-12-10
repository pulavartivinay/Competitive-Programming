Question Link: https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/description/

Solution:
int maximumLength(string s) {
    int n = s.length();
    int ans = INT_MIN;
    unordered_map<string, int> mp;

    for(int i=0;i<n;i++)
    {
        string curr_s = "";
        curr_s += s[i];
        mp[curr_s]++;
        if(mp[curr_s] == 3) ans = max(ans, (int) curr_s.length());
        for(int j=i+1;j<n;j++)
        {
            curr_s += s[j]; 
            int k = i+1;
            while(k <= j && s[k] == s[k-1]) k++;
            if(k == j+1) mp[curr_s]++;
            else break;

            if(mp[curr_s] == 3) ans = max(ans, (int) curr_s.length());
        }
    }
    
    return (ans != INT_MIN) ? ans : -1;
}
