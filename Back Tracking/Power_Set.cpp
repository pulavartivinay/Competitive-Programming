Question Link: https://www.geeksforgeeks.org/problems/power-set4302/1

Solution:
void backTrack(int i, int len, string& s, string curr_s, vector<string>& ans)
{
    if(i == len) {
        if(curr_s.length() > 0) ans.push_back(curr_s);
        return;
    }
    
    backTrack(i+1, len, s, curr_s+s[i], ans);
    backTrack(i+1, len, s, curr_s, ans);
}
vector<string> AllPossibleStrings(string s){
    // Code here
    int len = s.length();
    vector<string> ans;
    string curr_s = "";
    backTrack(0, len, s, curr_s, ans);
    
    sort(ans.begin(), ans.end());
    
    return ans;
}
