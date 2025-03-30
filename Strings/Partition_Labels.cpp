Question Link: https://leetcode.com/problems/partition-labels/description/

Solution:
vector<int> partitionLabels(string s) {
    int n = s.length();
    vector<int> ans;
    vector<int> last(26, -1);

    for(int i=0;i<n;i++) last[s[i] - 'a'] = i;

    int i = 0, j = 0, cnt = 0;
    while(j < n)
    {
        cnt = max(cnt, last[s[j] - 'a']);

        if(j == cnt)
        {
            ans.push_back(cnt - i + 1);
            i = cnt+1;
            cnt = 0;
        }

        j++;
    }

    return ans;
}
