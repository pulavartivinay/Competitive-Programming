Question Link: https://practice.geeksforgeeks.org/problems/pairs-violating-bst-property/1#

Solution Link:

void InOrder(Node* root, vector<long long int>& li)
{
    if(root)
    {
        InOrder(root->left, li);
        li.push_back(root->data);
        InOrder(root->right, li);
    }
}
int pairsViolatingBST(Node *root, int n){
          /*Your code here */
        long long int mod = (pow(10, 9) + 7);
        vector<long long int> li;
        InOrder(root, li);
        int gh = li.size();
        long long int count = 0;
        for(int i=0;i<(gh-1);i++)
        {
            for(int j=i+1;j<gh;j++)
            {
                if(li[i] >= li[j])
                {
                    count = count + 1;
                }
            }
        }
        return count%mod;
}
