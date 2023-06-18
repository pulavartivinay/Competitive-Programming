Question: https://www.hackerrank.com/contests/logicmojo-feb23/challenges/left-view-of-binary-tree-2/problem

Solution:
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    
    map<int,int> m;
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        int curr_ind = p.first;
        int curr_lvl = p.second;
        
        if(m.count(curr_lvl) == 0) m[curr_lvl] = arr[curr_ind];
        
        if(2*curr_ind+1 < n && arr[2*curr_ind+1] != -1) q.push({2*curr_ind+1, curr_lvl+1});
        if(2*curr_ind+2 < n && arr[2*curr_ind+2] != -1) q.push({2*curr_ind+2, curr_lvl+1});
        
        q.pop();
    }
    
    for(auto it:m)
    {
        cout << it.second << endl;
    }
    
    return 0;
}
