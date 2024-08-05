Question: https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

Solution:
vector <int> bottomView(Node *root)
{
    // Your Code Here
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    
    q.push({root, 0});
    // level order traversal
    while(!q.empty())
    {
        pair<Node*, int> p = q.front();
        q.pop();
        
        Node* curr = p.first;
        int lvl = p.second;
        
        //update the map
        mp[lvl] = curr->data;
        
        if(curr->left) q.push({curr->left, lvl-1});
        if(curr->right) q.push({curr->right, lvl+1});
    }
    
    vector<int> ans;
    for(ele : mp)
    {
        //cout << ele.first << " " << ele.second << endl;
        ans.push_back(ele.second);
    }
    
    return ans;
}
