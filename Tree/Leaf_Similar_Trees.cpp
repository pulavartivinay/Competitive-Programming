Question Link: https://leetcode.com/problems/leaf-similar-trees/description/

Solution:
void leafSequence(TreeNode* root, vector<int>& v)
{
    if(!root) return;

    leafSequence(root->left, v);
    if(!root->left && !root->right) v.push_back(root->val);
    leafSequence(root->right, v);
}
bool isEqual(vector<int>& v1, vector<int>& v2)
{
    int n = v1.size(), m = v2.size();
    if(n != m) return false;

    for(int i=0;i<n;i++)
    {
        if(v1[i] != v2[i]) return false;
    }

    return true;
}
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> v1, v2;
    leafSequence(root1, v1);
    leafSequence(root2, v2);

    return isEqual(v1, v2);
}
