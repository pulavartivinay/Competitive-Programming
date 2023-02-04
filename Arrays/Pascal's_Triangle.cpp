Question Link: https://leetcode.com/problems/pascals-triangle/description/

Solution:
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++)
        {
            if(i == 1) ans.push_back({1});
            else if(i == 2) ans.push_back({1,1});
            else
            {
                vector<int> temp(i,1);
                for(int j=1;j<(i-1);j++)
                {
                    temp[j] = ans[i-2][j-1] + ans[i-2][j];
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
