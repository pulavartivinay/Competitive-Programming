Question Link: https://www.codingninjas.com/studio/problems/983635?topList=striver-sde-sheet-problems&leftPanelTabValue=PROBLEM

Solution:
void helper(string &s, string curr_s, unordered_map<string, bool> &mp, int idx, vector<string> &ans)
{
    if(idx == s.length())
    {
        ans.push_back(curr_s);
        return;
    }

    string temp_s = "";


    for(int i=idx;i<s.length();i++)
    {
        temp_s += s[i];
        if(mp[temp_s]) helper(s, curr_s + temp_s + " ", mp, i+1, ans);
    }

    return;
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    vector<string> ans;
    string curr_s = "";
    unordered_map<string, bool> mp;

    for(int i=0;i<dictionary.size();i++)
    {
        mp[dictionary[i]] = true;
    }

    helper(s, curr_s, mp, 0, ans);

    return ans;
}
