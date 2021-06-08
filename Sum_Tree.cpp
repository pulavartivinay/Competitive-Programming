Question Link: https://practice.geeksforgeeks.org/problems/sum-tree/1

Solution Link: 

int sum(Node* root, int& flag)
{
    if(flag == 1)
    {
        if(root)
        {
            if(root->left == NULL && root->right == NULL)
            {
                return root->data;
            }
            else
            {
                int left_sum = sum(root->left, flag);
                int right_sum = sum(root->right, flag);
                if(root->data != left_sum + right_sum)
                {
                    flag = 0;
                }
                return (left_sum + root->data + right_sum);
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
class Solution
{
    public:
    bool isSumTree(Node* root)
    {
         // Your code here
         int flag = 1;
         int temp = sum(root, flag);
         return flag;
    }
};
