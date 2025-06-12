Question Link: https://leetcode.com/problems/word-ladder/description/

Solution:
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());

    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    st.erase(beginWord);

    while(!q.empty())
    {
        pair<string, int> p = q.front();
        q.pop();

        string curr = p.first, temp = p.first;
        int len = p.second;

        for(int i=0;i<curr.size();i++)
        {
            for(int j=0;j<26;j++)
            {
                temp[i] = 'a' + j;
                if(st.find(temp) != st.end())
                {
                    if(temp == endWord) return len+1;
                    q.push({temp, len+1});
                    st.erase(temp);
                }
            }
            temp[i] = curr[i];
        }
    }

    return 0;
}
