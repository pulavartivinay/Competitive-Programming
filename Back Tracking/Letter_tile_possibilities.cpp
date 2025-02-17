Question Link: https://leetcode.com/problems/letter-tile-possibilities/description/

Solution:
void backTrack(vector<int>& freq, int& ans)
{
    for(int i=0;i<26;i++)
    {
        if(freq[i] != 0)
        {
            freq[i]--;
            ans++;
            backTrack(freq, ans);
            freq[i]++;
        }
    }
}
int numTilePossibilities(string tiles) {
    int n = tiles.length();
    int ans = 0;

    vector<int> freq(26, 0);
    for(int i=0;i<n;i++) freq[tiles[i] - 'A']++;

    backTrack(freq, ans);

    return ans;
}
