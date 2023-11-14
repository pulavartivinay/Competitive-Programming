Question Link: https://leetcode.com/problems/binary-search-tree-iterator/description/

Solution:
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        TreeNode* tr = root;
        while(tr)
        {
            st.push(tr);
            tr = tr->left;
        }
    }
    
    int next() {
        int ans = st.top()->val;

        TreeNode* tr = st.top()->right;
        st.pop();
        while(tr)
        {
            st.push(tr);
            tr = tr->left;
        }

        return ans;
    }
    
    bool hasNext() {
        return (!st.empty());
    }
};
