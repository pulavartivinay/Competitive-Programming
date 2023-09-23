Question Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

Solution:
TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int PreStart, int PreEnd, int InStart, int InEnd, unordered_map<int, int>& mp)
{
    if(PreStart > PreEnd && InStart > InEnd) return NULL;

    TreeNode* root = new TreeNode(preorder[PreStart]);
    int ind = mp[preorder[PreStart]];
    int left_tree_elems = ind - InStart;
    root->left = buildTreeHelper(preorder, inorder, PreStart+1, PreStart+left_tree_elems, InStart, ind-1, mp);
    root->right = buildTreeHelper(preorder, inorder, PreStart+left_tree_elems+1, PreEnd, ind+1, InEnd, mp);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    int PreStart = 0, PreEnd = n-1;
    int InStart = 0, InEnd = n-1;

    unordered_map<int, int> mp;

    for(int i=0;i<n;i++)
    {
        mp[inorder[i]] = i;
    }

    return buildTreeHelper(preorder, inorder, PreStart, PreEnd, InStart, InEnd, mp);
}
