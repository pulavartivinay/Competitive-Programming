Question Link: https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

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
    int KthSmallestElement(Node *root, int K)
    {
        //add code here.
        vector<int> li;
        InOrder(root, li);
        if(K > li.size())
        {
            return -1;
        }
        return li[K-1];
    }
