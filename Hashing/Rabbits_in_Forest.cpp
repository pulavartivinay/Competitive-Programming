Question Link: https://leetcode.com/problems/rabbits-in-forest/description/

Solution:
int numRabbits(vector<int>& answers) {
    int ans = 0;
    int n = answers.size();

    unordered_map<int, int> mp;

    for(int i=0;i<n;i++)
    {
        mp[answers[i]]++;
    }

    int groups = 0;
    double d = 0.0;
    for(auto k:mp)
    {
        d = (double)(k.second)/(double)(1 + k.first);
        groups = ceil(d);
        ans += groups * (1 + k.first);
    }

    return ans;
}
