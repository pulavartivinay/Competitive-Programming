Question Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

Solution:
TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int InStart, int InEnd, int PostStart, int PostEnd, unordered_map<int, int>& mp)
{
    if(PostStart > PostEnd && InStart > InEnd) return NULL;

    TreeNode* root = new TreeNode(postorder[PostEnd]);
    int ind = mp[postorder[PostEnd]];
    int right_tree_elems = InEnd - ind;
    root->left = buildTreeHelper(inorder, postorder, InStart, ind-1, PostStart, PostEnd-right_tree_elems-1, mp);
    root->right = buildTreeHelper(inorder, postorder, ind+1, InEnd, PostEnd-right_tree_elems, PostEnd-1, mp);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
{
    int n = postorder.size();
    int InStart = 0, InEnd = n-1;
    int PostStart = 0, PostEnd = n-1;

    unordered_map<int, int> mp;

    for(int i=0;i<n;i++)
    {
        mp[inorder[i]] = i;
    }

    return buildTreeHelper(inorder, postorder, InStart, InEnd, PostStart, PostEnd, mp);
}
