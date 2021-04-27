Question link: https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1#

Solution:

int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int m = grid[0].size(); //number of columns
        int n = grid.size();    //number of rows
        int A[n][m];
        int visited[n][m];
        queue<vector<int>> li;
        vector<vector<int>> fresh;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                A[i][j] = 0;
                visited[i][j] = 0;
                if(grid[i][j] == 2)
                {
                    li.push({i,j,0});
                }
                if(grid[i][j] == 1)
                {
                    fresh.push_back({i,j});
                }
            }
        }
        while(!li.empty())
        {
            int a,b,c;
            vector<int> t = li.front();
            a = t[0];
            b = t[1];
            c = t[2];
            li.pop();
            if(b-1 >= 0) //left
            {
                if(grid[a][b-1] == 1 && visited[a][b-1] == 0)
                {
                    visited[a][b-1] = 1;
                    li.push({a,b-1,c+1});
                    A[a][b-1] = c+1;
                }
            }
            if(b+1 < m) //right
            {
                if(grid[a][b+1] == 1 && visited[a][b+1] == 0)
                {
                    visited[a][b+1] = 1;
                    li.push({a,b+1,c+1});
                    A[a][b+1] = c+1;
                }
            }
            if(a-1 >= 0) //up
            {
                if(grid[a-1][b] == 1 && visited[a-1][b] == 0)
                {
                    visited[a-1][b] = 1;
                    li.push({a-1,b,c+1});
                    A[a-1][b] = c+1;
                }
            }
            if(a+1 < n) //down
            {
                if(grid[a+1][b] == 1 && visited[a+1][b] == 0)
                {
                    visited[a+1][b] = 1;
                    li.push({a+1,b,c+1});
                    A[a+1][b] = c+1;
                }
            }
        }
        int time = 0;
        for(int i=0;i<fresh.size();i++)
        {
            vector<int> ji = fresh[i];
            int k,l;
            k = ji[0];
            l = ji[1];
            if(A[k][l] == 0)
            {
                return -1;
            }
            else
            {
                time = max(time,A[k][l]);
            }
        }
        return time;
