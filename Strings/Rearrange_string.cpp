Question Link: https://practice.geeksforgeeks.org/problems/rearrange-a-string4100/1

Solution:

string arrangeString(string str)
{
    //code here.
    int n = str.length();
    string ans = "";
    int sum = 0;
    vector<int> v(26,0);
    for(int i=0;i<n;i++)
    {
        if(0 <= str[i]-'0' && str[i]-'0' <= 9) sum += str[i]-'0';
        else v[str[i]-'A']++;
    }
    for(int i=0;i<26;i++)
    {
        int c = v[i];
        while(c > 0)
        {
            ans += 'A'+i;
            c--;
        }
    }
    ans += to_string(sum);
    return ans;
}
