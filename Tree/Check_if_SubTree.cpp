Question Link: https://practice.geeksforgeeks.org/problems/check-if-subtree/1

Solution:

bool equal(Node* T, Node* S)
{
    if(T && S)
    {
        if(T->data == S->data)
        {
            return ( equal(T->left, S->left) & equal(T->right, S->right) );
        }
        else return false;
    }
    else if(T == NULL && S == NULL) return true;
    else return false;
}
bool PreOrder(Node* T, Node* S)
{
    if(T)
    {
        bool ans = false;
        if(T->data == S->data)
        {
            // cout << T->data << endl;
            ans = equal(T,S);
            // cout << ans << endl;
        }
        return (ans | PreOrder(T->left,S) | PreOrder(T->right,S) );
    }
    else return false;
}
//Function to check if S is a subtree of tree T.
bool isSubTree(Node* T, Node* S) 
{
    // Your code here
    if(T == NULL && S == NULL) return true;
    if(T == NULL | S == NULL) return false;
    return PreOrder(T, S);
}
