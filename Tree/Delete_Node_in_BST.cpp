Question Link: https://leetcode.com/problems/delete-node-in-a-bst/description/?envType=study-plan-v2&envId=leetcode-75

Solution:
TreeNode* findSuccessor(TreeNode* root)
{
    TreeNode* temp = root->right;
    while(temp->left) temp = temp->left;

    return temp;
}
TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return root;

    if(key < root->val) root->left = deleteNode(root->left, key);
    else if(key > root->val) root->right = deleteNode(root->right, key);
    else
    {
        // found the key in the BST tree
        // key is child
        if(!root->left && !root->right) return NULL;
        if(root->left && !root->right) return root->left;
        if(!root->left && root->right) return root->right;

        // left and right child are present
        TreeNode* succ = findSuccessor(root);
        swap(root->val, succ->val);

        root->right = deleteNode(root->right, key);
    }

    return root;
}
