Question Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/

Solution:
TreeNode* f(int a, int b, vector<int>& preorder, int c, int d, vector<int>& postorder,
                unordered_map<int, int>& pre_mp, unordered_map<int, int>& post_mp)
{
    if(a > b) return NULL;
    // leaf node
    if(a == b && c == d) return new TreeNode(preorder[a]);

    // root creation
    TreeNode* root = new TreeNode(preorder[a]);

    // left child creation
    int pre_ind  = pre_mp[postorder[d-1]];
    int post_ind = post_mp[preorder[a+1]];
    root->left = f(a+1, pre_ind-1, preorder, c, post_ind, postorder, pre_mp, post_mp);

    // right child creation
    int t = root->left ? min(post_ind+1, d-1) : c;
    root->right = f(pre_ind, b, preorder, t, d-1, postorder, pre_mp, post_mp);

    return root;
}
TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    int n = preorder.size();
    unordered_map<int, int> pre_mp, post_mp;
    for(int i=0;i<n;i++)
    {
        pre_mp[preorder[i]] = i;
        post_mp[postorder[i]] = i;
    }
    return f(0, n-1, preorder, 0, n-1, postorder, pre_mp, post_mp);

    // root  --> 1
    // left  --> pre(1, 3)   post(0, 2)
    // {
    //     root  --> 2 --> root creation
    //     left  --> pre(2, 2) post(0, 0) --> create a node with the value and return it
    //     right --> pre(3, 3) post(1, 1) --> create a node with the value and return it

    //     return root node
    // }
    // right --> pre(4, n-1) post(3, n-2)
}
