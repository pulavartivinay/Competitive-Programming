Question Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

Solution:
TreeNode* InOrderPredecessor(TreeNode* root, int key)
{
    if(root)
    {
        if(key <= root->val) return InOrderPredecessor(root->left, key);
        else {
            TreeNode* store = InOrderPredecessor(root->right, key);
            return (store ? store : root);
        }
    }
    return NULL;
}

TreeNode* InOrderSuccessor(TreeNode* root, int key)
{
    if(root)
    {
        if(key >= root->val) return InOrderSuccessor(root->right, key);
        else {
            TreeNode* store = InOrderSuccessor(root->left, key);
            return (store ? store : root);
        }
    }
    return NULL;
}

bool findTarget(TreeNode* root, int k) {
    TreeNode *left_node = root, *right_node = root;
    while(left_node->left) left_node = left_node->left;
    while(right_node->right) right_node = right_node->right;

    while(left_node->val < right_node->val)
    {
        int a = left_node->val;
        int b = right_node->val;

        if(a+b == k) return true;
        else if(a+b < k) left_node = InOrderSuccessor(root, a);
        else right_node = InOrderPredecessor(root, b);
    }
    return false;        
}
