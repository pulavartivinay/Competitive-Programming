Question Link: https://practice.geeksforgeeks.org/problems/n-digit-numbers-with-digits-in-increasing-order5903/1#

Solution:

void BackTrack(vector<int>& ans, vector<int> vis, int num, int i, int N)
{
    if(i>9) return;
    if(vis[i]) return;
    // cout << i << " " << num << " ";

    if(num != 0) num = num*10;
    num += i;
    vis[i] = 1;
    string a = to_string(num);
    if(a.length() == N) 
    {
        ans.push_back(num);
        return;
    }

    for(int j=i+1;j<10;j++)
    {
        BackTrack(ans, vis, num, j, N);
    }
    vis[i] = 0;
}
vector<int> increasingNumbers(int N)
{
    vector<int> ans;
    if(N == 1)
    {
        for(int i=0;i<10;i++)
        {
            ans.push_back(i);
        }
        return ans;
    }
    for(int i=1;i<=9;i++)
    {
        vector<int> vis(11,0);
        int num = 0;
        BackTrack(ans, vis, num, i, N);
    }
    return ans;
    // Write Your Code here
}
