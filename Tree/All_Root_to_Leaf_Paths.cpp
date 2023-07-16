Question Link: https://www.codingninjas.com/studio/problems/all-root-to-leaf-paths-in-binary-tree._983599?leftPanelTab=0

Solution:
void all_paths_from_root(BinaryTreeNode<int> *root, vector<string>& ans, string s)
{
    if(root)
    {
        if(s.length() == 0) s += to_string(root->data);
        else {
            s += ' ';
            s += to_string(root->data);
        }
        if(!root->left && !root->right) ans.push_back(s);
        all_paths_from_root(root->left, ans, s);
        all_paths_from_root(root->right, ans, s);
    }
}

vector < string > allRootToLeaf(BinaryTreeNode < int > * root) {
    // Write your code here.
    vector<string> ans;
    string s;
    all_paths_from_root(root, ans, s);
    return ans;
}
