Question Link: https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/description/

Solution:
void backTrack(int ind, int n, int len, vector<bool>& visited, vector<int>& ans, bool& found)
{
    if(found) return;
    if(ind == len)
    {
        found = true;
        return;
    }

    if(ans[ind] != 0)
    {
        backTrack(ind+1, n, len, visited, ans, found);
        if(found) return;
    }

    for(int num=n;num>=1;num--)
    {
        if(!visited[num] && ans[ind] == 0)
        {
            if(num != 1)
            {
                if(ind+num < len && ans[ind+num] == 0)
                {
                    visited[num] = true;
                    ans[ind] = num;
                    ans[ind+num] = num;
                    backTrack(ind+1, n, len, visited, ans, found);
                    if(found) return;
                    visited[num] = false;
                    ans[ind] = 0;
                    ans[ind+num] = 0;
                }
            }
            else
            {
                cout << ind << " " << num << endl;
                // handle num = 1 case
                visited[num] = true;
                ans[ind] = num;
                backTrack(ind+1, n, len, visited, ans, found);
                if(found) return;
                visited[num] = false;
                ans[ind] = 0;
            }
        }
    }
}
vector<int> constructDistancedSequence(int n) {
    int len = (2*n) - 1;
    vector<int> ans(len, 0);
    vector<bool> visited(n+1, false);
    bool found = false;

    backTrack(0, n, len, visited, ans, found);

    return ans;
}
