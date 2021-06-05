Question Link: https://practice.geeksforgeeks.org/problems/foldable-binary-tree/1

Solution Link:

bool check(Node* t1, Node* t2)
{
    if(t1 == NULL && t2 == NULL)
    {
        return true;
    }
    else if(t1 == NULL && t2 != NULL)
    {
        return false;
    }
    else if(t1 != NULL && t2 == NULL)
    {
        return false;
    }
    else
    {
        if(check(t1->left, t2->right) && check(t1->right, t2->left))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
bool IsFoldable(Node* root)
{
    // Your code goes here
    if(root == NULL)
    {
        return true;
    }
    else
    {
        return check(root->left, root->right);
    }
}
