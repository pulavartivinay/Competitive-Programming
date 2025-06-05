Question Link: https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/

Solution:
class Solution {
public:
    char findPar(char u, vector<char>& par)
    {
        if(u == par[u - 'a']) return u;
        return par[u - 'a'] = findPar(par[u - 'a'], par);
    }
    void unionBysize(char u, char v, vector<int>& size, vector<char>& par)
    {
        char ulp_u = findPar(u, par);
        char ulp_v = findPar(v, par);

        if(ulp_u == ulp_v) return;
        if((ulp_u - 'a') > (ulp_v - 'a'))
        {
            par[ulp_u - 'a'] = ulp_v;
            size[ulp_v - 'a'] += size[ulp_u - 'a'];
        }
        else
        {
            par[ulp_v - 'a'] = ulp_u;
            size[ulp_u - 'a'] += size[ulp_v - 'a'];
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        string ans = "";

        vector<int> size(26, 1);
        vector<char> par(26);
        for(int i=0;i<26;i++) par[i] = 'a' + i;

        for(int i=0;i<n;i++)
        {
            unionBysize(s1[i], s2[i], size, par);
        }

        for(int i=0;i<baseStr.size();i++)
        {
            ans += findPar(baseStr[i], par);
        }

        return ans;
    }
};
