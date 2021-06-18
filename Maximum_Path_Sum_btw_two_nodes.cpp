Question Link: https://practice.geeksforgeeks.org/problems/maximum-path-sum/1

Solution:

int maxSum(Node* root)
    {
        if(root)
        {
            if(root->left == NULL && root->right == NULL)
            {
                return root->data;
            }
            else if(root->left != NULL && root->right == NULL)
            {
                return (root->data + maxSum(root->left));
            }
            else if(root->left == NULL && root->right != NULL)
            {
                return (root->data + maxSum(root->right));
            }
            return max(root->data + maxSum(root->left), root->data + maxSum(root->right));
        }
        else
        {
            return INT_MIN;
        }
    }
    int helper(Node* root)
    {
        int a = INT_MIN;
        int b = INT_MIN;
        int c = INT_MIN;
        int d = INT_MIN;
        if(root->left != NULL && root->right != NULL)
        {
            a = helper(root->left);
            b = helper(root->right);
            c = maxSum(root->left);
            d = maxSum(root->right);
            return max(max(a, b), c + d + root->data);
        }
        else if(root->left != NULL && root->right == NULL)
        {
            return helper(root->left);
        }
        else if(root->left == NULL && root->right != NULL)
        {
            return helper(root->right);
        }
        else
        {
            return INT_MIN;
        }
    }
    int maxPathSum(Node* root)
    {
        // code here
        int ans = 0;
        Node* travel = root;
        while(travel->left == NULL | travel->right == NULL)
        {
            ans = ans + travel->data;
            if(travel->left == NULL && travel->right == NULL)
            {
                return ans;
            }
            if(travel->left != NULL)
            {
              travel = travel->left; 
            }
            else
            {
                travel = travel->right;
            }
        }
        return helper(root);
    }
