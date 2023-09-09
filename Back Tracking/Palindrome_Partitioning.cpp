Question Link: https://leetcode.com/problems/palindrome-partitioning/

Solution:
int isPalindrome(string s)
{
    int i=0,j=s.length()-1;
    while(i <= j && s[i] == s[j])
    {
        i++;
        j--;
    }
    
    if(i <= j) return false;
    else return true;
}

void dp(int i, int n, string s, vector<string> temp_ans, vector<vector<string>>& ans)
{
    if(i >= n)
    {
        ans.push_back(temp_ans);
        return;
    }
    
    string temp_s = "";
    for(int j=i;j<n;j++)
    {
        temp_s += s[j];
        if(isPalindrome(temp_s))
        {
            temp_ans.push_back(temp_s);
            dp(j+1, n, s, temp_ans, ans);
            temp_ans.pop_back();
        }
    }
    return;
}

vector<vector<string>> partition(string s, int n) {
    vector<vector<string>> ans;
    
    string temp_s = "";
    for(int i=0;i<n;i++)
    {
        temp_s += s[i];
        if(isPalindrome(temp_s))
        {
            vector<string> temp_ans;
            temp_ans.push_back(temp_s);
            dp(i+1, n, s, temp_ans, ans);
        }
    }
    
    return ans;
}
