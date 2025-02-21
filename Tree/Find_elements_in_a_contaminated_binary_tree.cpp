Question Link: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/

Solution:
class FindElements {
public:
    unordered_map<int, int> mp;
    void set_value(TreeNode* root, int val)
    {
        if(root)
        {
            root->val = val;
            mp[val]++;
            set_value(root->left, 2*val + 1);
            set_value(root->right, 2*val + 2);
        }
    }
    FindElements(TreeNode* root) {
        set_value(root, 0);
    }
    
    bool find(int target) {
        return mp[target] != 0;
    }
};
