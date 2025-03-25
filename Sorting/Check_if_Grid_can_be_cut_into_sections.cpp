Question Link: https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/description/

Solution:
bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    vector<pair<int, int>> ver, hor;
    vector<int> v;

    for(int i=0;i<rectangles.size();i++)
    {
        v = rectangles[i];
        ver.push_back({v[0], 1});
        ver.push_back({v[2], -1});
        hor.push_back({v[1], 1});
        hor.push_back({v[3], -1});
    }

    int cnt = 0, br = 0;
    // sort the vertical array
    sort(ver.begin(), ver.end());
    for(int i=0;i<ver.size();i++)
    {
        cnt += ver[i].second;
        if(cnt == 0) br++;

        if(br == 2 && i < (ver.size() - 1)) return true;
    }

    cnt = 0, br = 0;
    // sort the horizontal array
    sort(hor.begin(), hor.end());
    for(int i=0;i<hor.size();i++)
    {
        cnt += hor[i].second;
        if(cnt == 0) br++;

        if(br == 2 && i < (hor.size() - 1)) return true;
    }

    return false;
}
