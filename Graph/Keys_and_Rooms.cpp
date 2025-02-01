Question Link: https://leetcode.com/problems/keys-and-rooms/description/

Solution:
void DFS(int src, vector<vector<int>>& rooms, vector<bool>& vis, int& cnt)
{
    vis[src] = true;
    cnt++;

    for(int i=0;i<rooms[src].size();i++)
    {
        if(!vis[rooms[src][i]]) DFS(rooms[src][i], rooms, vis, cnt);
    }

    return;
}
bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();

    vector<bool> vis(n, false);
    int cnt = 0;

    DFS(0, rooms, vis, cnt);

    return (cnt == n);
}
