Question Link: https://leetcode.com/problems/find-unique-binary-string/description/

Solution:
void backTrack(int i, int n, unordered_map<string, int>& mp,
                   string s, string& ans)
{
    if(ans != "") return;
    if(s.length() == n)
    {
        if (mp[s] == 0)
        {
            ans = s;
            return;
        }
    }
    if(i >= n) return;

    backTrack(i+1, n, mp, s+'0', ans);
    backTrack(i+1, n, mp, s+'1', ans);
}

string findDifferentBinaryString(vector<string>& nums) {
    int n = nums.size();
    unordered_map<string, int> mp;
    for(int i=0;i<n;i++)
    {
        mp[nums[i]]++;
    }
    string ans = "", s = "";
    backTrack(0, n, mp, s, ans);
    return ans;
}
