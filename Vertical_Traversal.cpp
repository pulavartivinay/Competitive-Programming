Question Link: https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1/


Solution Link:

map<Node*,int> value;
    
    void computeValue(Node* root)
    {
        if(root != NULL)
        {
            if(root->left != NULL)
            {
                value[root->left] = value[root] - 1;
                computeValue(root->left);
            }
            if(root->right != NULL)
            {
                value[root->right] = value[root] + 1;
                computeValue(root->right);
            }
        }
    }
    
    static bool compareVector(vector<int> a, vector<int> b)
    {
        return (a[1] < b[1]);
    }
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> ans;
        value[root] = 2500;
        computeValue(root);
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> level_order;
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            level_order.push_back({temp->data, value[temp]});
            if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
        stable_sort(level_order.begin(),level_order.end(),compareVector);
        for(int i=0;i<(level_order.size());i++)
        {
            ans.push_back(level_order[i][0]);
        }
        return ans;
        // cout << endl;
    }
};
