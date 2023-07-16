Question Link: https://www.codingninjas.com/studio/problems/981269?topList=striver-sde-sheet-problems&leftPanelTab=0

Solution:
void all_traversals(BinaryTreeNode<int> *root, vector<int>& Pre, vector<int>& In, vector<int>& Post)
{
    if(root)
    {
        Pre.push_back(root->data);
        all_traversals(root->left, Pre, In, Post);
        In.push_back(root->data);
        all_traversals(root->right, Pre, In, Post);
        Post.push_back(root->data);
    }
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> Pre, In, Post;
    all_traversals(root, Pre, In, Post);
    ans.push_back(In);
    ans.push_back(Pre);
    ans.push_back(Post);
    return ans;
}
