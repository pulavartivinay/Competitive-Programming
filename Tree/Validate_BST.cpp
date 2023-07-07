Question Link: https://leetcode.com/problems/validate-binary-search-tree/description/

Solution:
bool InOrder(TreeNode* root, int& prev, int& cnt)
{
    if(!root) return true;
    bool a = InOrder(root->left, prev, cnt);
    if(a == false) return false;
    if(cnt == 0) prev = root->val;
    else if (root->val > prev) prev = root->val;
    else return false;
    cnt++;
    bool b = InOrder(root->right, prev, cnt);
    if(b == false) return false;
    return true;
}
bool isValidBST(TreeNode* root) {
    int prev = 0, cnt = 0;
    return InOrder(root, prev, cnt);
}
