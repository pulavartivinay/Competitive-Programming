Question Link: https://leetcode.com/problems/interval-list-intersections/

Solution:

vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) 
{
    int m = firstList.size();
    int n = secondList.size();
    vector<vector<int>> ans;
    int i = 0;
    int j = 0;
    while(i<m && j<n)
    {
        if(max({firstList[i][0],secondList[j][0]}) <= min({firstList[i][1],secondList[j][1]}))
        {
            ans.push_back({max({firstList[i][0],secondList[j][0]}), min({firstList[i][1],secondList[j][1]})});
            if(firstList[i][1] < secondList[j][1]) i++;
            else j++;
        }
        else
        {
            if(firstList[i][1] < secondList[j][1]) i++;
            else j++;
        }
    }
    return ans;
}
