Question Link: https://practice.geeksforgeeks.org/problems/cousins-of-a-given-node/1#

Solution:

void find_par_and_h(Node* root, Node* node_to_find, Node* p, Node*& pfind, int h, int& hfind)
{
    if(root)
    {
        // cout << root->data << endl;
        if(root == node_to_find)
        {
            pfind = p;
            hfind = h;
            return;
        }
        find_par_and_h(root->left, node_to_find, root, pfind, h+1, hfind);
        find_par_and_h(root->right, node_to_find, root, pfind, h+1, hfind);
    }

}
void PreOrder(Node* root, Node* p, int h, Node* pfind, int& hfind, vector<int>& ans)
{
    if(root)
    {
        if(h == hfind && p != pfind)
        {
            ans.push_back(root->data);
            return;
        }
        PreOrder(root->left, root, h+1, pfind, hfind, ans);
        PreOrder(root->right, root, h+1, pfind, hfind, ans);
    }
}
vector<int> printCousins(Node* root, Node* node_to_find)
{
    //code here
    vector<int> ans;
    Node* pfind = NULL;
    int hfind = 0;
    find_par_and_h(root, node_to_find, NULL, pfind, 0, hfind);
    // cout << hfind << " " << pfind->data << endl;
    PreOrder(root, NULL, 0, pfind, hfind, ans);
    if(ans.size() == 0) ans.push_back(-1);
    return ans;
}
