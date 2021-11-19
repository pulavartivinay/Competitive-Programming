Question Link: https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1

Solution:

void InOrder(Node* root, vector<int>& li)
    {
        if(root)
        {
            InOrder(root->left, li);
            li.push_back(root->data);
            InOrder(root->right, li);
        }
    }
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        vector<int> li;
        InOrder(root, li);
        vector<int>::iterator hi;
        hi = upper_bound(li.begin(), li.end(), x->data);
        if(hi == li.end())
        {
            return NULL;
        }
        int val = li[hi - li.begin()];
        Node* ans = root;
        ans->data = val;
        ans->left = NULL;
        ans->right = NULL;
        return ans;
    }
