Question Link: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#


Solution Link: 

vector<Node*> leaf;
    void computeLeaf(Node *root)
    {
        if(root != NULL)
        {
            if(root->left != NULL)
            {
                computeLeaf(root->left);
            }
            if(root->right != NULL)
            {
                computeLeaf(root->right);
            }
            
            if(root->left == NULL && root->right == NULL)
            {
                leaf.push_back(root);
            }
        }
    }
    
    vector <int> printBoundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        computeLeaf(root);
        Node* travel = root;
        //left boundary
        if(root->left != NULL)
        {
            while(travel->left != NULL || travel->right != NULL)
            {
                if(travel->left != NULL)
                {
                    ans.push_back(travel->data);
                    travel = travel->left;
                }
                else
                {
                    ans.push_back(travel->data);
                    travel = travel->right;
                }
            }
        }
        else
        {
            ans.push_back(travel->data);
        }
        
        //all leaf nodes
        for(int i=0;i<(leaf.size());i++)
        {
            ans.push_back(leaf[i]->data);
        }
        vector<int> temp;
        travel = root->right;
        //right boundary
        if(travel != NULL)
        {
            while(travel->right != NULL || travel->left != NULL)
            {
                if(travel->right != NULL)
                {
                    temp.push_back(travel->data);
                    travel = travel->right;
                }
                else
                {
                    temp.push_back(travel->data);
                    travel = travel->left;
                }
            }
            
            reverse(temp.begin(),temp.end());
            for(int i=0;i<(temp.size());i++)
            {
                ans.push_back(temp[i]);
            }
        }
        
        return ans;
    }
