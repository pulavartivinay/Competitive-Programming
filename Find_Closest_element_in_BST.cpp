Question Link: https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1

Solution Link:

int minDiff(Node *root, int K)
    {
        //Your code here
        int ans = abs(root->data - K);
        Node* travel = root;
        while(1)
        {
            //if the given value is greater than root value, then we will travel right subtree.
            if(travel->right && travel->data < K)
            {
                travel = travel->right;
                ans = min(ans, abs(travel->data - K));
            }
            //if the given value is lesser than root value, then we will travel left sub tree.
            else if(travel->left && travel->data > K)
            {
                travel = travel->left;
                ans = min(ans, abs(travel->data - K));
            }
            //if the given value is in the tree, then the closest element is the given value and return 0.
            else if(travel->data == K)
            {
                ans = 0;
                break;
            }
            //if there is nothing to travel beyond, just break the loop and return the answer.
            else
            {
                break;
            }
        }
        return ans;
    }
