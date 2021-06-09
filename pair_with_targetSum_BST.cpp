Question Link: https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1

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
    int isPairPresent(struct Node *root, int target)
    {
        vector<int> li;
        InOrder(root, li);
        int n = li.size();
        int low = 0;
        int high = n-1;
        int found = 0;
        while(low < high)
        {
            if(li[low] + li[high] == target)
            {
                found = 1;
                break;
            }
            else if(li[low] + li[high] < target)
            {
                low = low + 1;
            }
            else
            {
                high = high - 1;
            }
        }
        return found;
    }
