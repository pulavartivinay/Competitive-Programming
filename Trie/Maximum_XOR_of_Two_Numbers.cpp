Question Link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

Solution:

struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
    Node(int vl)
    {
        left = NULL;
        right = NULL;
        val = vl;
    }
};
int findMaximumXOR(vector<int>& nums) 
{
    struct Node* root = new Node(123);
    // cout << root->val << endl;
    int n = nums.size();
    for(int i=0;i<n;i++)
    {
        struct Node* curr = root;
        for(int j=31;j>=0;j--)
        {
            int a = ((nums[i] >> j) & 1);
            if(a)
            {
                if(curr->right == NULL) 
                {
                    struct Node* temp = new Node(nums[i] >> j);
                    curr->right = temp;
                }
                curr = curr->right;
            }
            else
            {
                if(curr->left == NULL) 
                {
                    struct Node* temp = new Node(nums[i] >> j);
                    curr->left = temp;
                }
                curr = curr->left;
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        int h = nums[i];
        struct Node* curr = root;
        int t = 0;
        for(int j=31;j>=0;j--)
        {
            int a = ((nums[i] >> j) & 1);
            if(a)
            {
                if(curr->left) curr = curr->left;
                else if(curr->right) 
                {
                    curr = curr->right;
                    t += pow(2,j);
                }
                else break;
            }
            else
            {
                if(curr->right) 
                {
                    curr = curr->right;
                    t += pow(2,j);
                }
                else if(curr->left) curr = curr->left;
                else break;
            }
        }
        ans = max(ans, t^h);
        // cout << nums[i] << " " << ans << endl;
    }
    return ans;
}
