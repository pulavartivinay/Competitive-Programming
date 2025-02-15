Question Link: https://leetcode.com/problems/find-the-punishment-number-of-an-integer/description/

Solution:
void backTrack(int curr_num, int ind, string s, int target, bool &possible)
{
    if(possible) return;
    if(ind == s.length() && curr_num == target)
    {
        possible = true;
        return;
    }

    int n = s.length();
    string temp = "";
    for(int i=ind;i<n;i++)
    {
        temp += s[i];
        backTrack(curr_num + stoi(temp), i+1, s, target, possible);
    }

}
int punishmentNumber(int n) {
    int ans = 0;

    for(int i=1;i<=n;i++)
    {
        string s = to_string(i * i);
        bool possible = false;
        backTrack(0, 0, s, i, possible);
        if(possible) ans += (i*i);
    }

    return ans;
}
