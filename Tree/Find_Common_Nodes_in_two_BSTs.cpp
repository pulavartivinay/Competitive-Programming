Question Link: https://practice.geeksforgeeks.org/problems/print-common-nodes-in-bst/1

Solution Link:

void InOrder(Node* root, vector<int>& li)
    {
        if(root)
        {
            InOrder(root->left, li);
            li.push_back(root->data);
            InOrder(root->right, li);
        }
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
        vector<int> a;
        vector<int> b;
        InOrder(root1, a);
        InOrder(root2, b);
        vector<int> ans;
        int n1 = a.size();
        int n2 = b.size();
        int t1 = 0;
        int t2 = 0;
        while(t1 < n1 && t2 < n2)
        {
            if(a[t1] < b[t2])
            {
                t1 = t1 + 1;
            }
            else if(a[t1] > b[t2])
            {
                t2 = t2 + 1;
            }
            else if(a[t1] == b[t2])
            {
                ans.push_back(a[t1]);
                t1 = t1 + 1;
                t2 = t2 + 1;
            }
        }
        return ans;
    }
