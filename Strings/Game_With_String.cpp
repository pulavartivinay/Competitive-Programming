Question Link: https://practice.geeksforgeeks.org/problems/game-with-string4100/1#

Solution:

int minValue(string s, int k){
        // code here
        map<char,int> m;
        for(int i=0;i<s.length();i++)
        {
            m[s[i] - 97] += 1;
        }
        vector<int> li;
        for(int i=0;i<26;i++)
        {
            li.push_back(m[i]);
        }
        while(k != 0)
        {
            sort(li.begin(), li.end(), greater<int>());
            li[0] = li[0] - 1;
            k--;
        }
        int ans = 0;
        for(int i=0;i<26;i++)
        {
            ans = ans + (pow(li[i],2));
        }
        return ans;
    }
