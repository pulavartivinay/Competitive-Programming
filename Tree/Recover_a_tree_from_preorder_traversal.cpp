Question Link: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/

Solution:
TreeNode* recoverFromPreorder(string traversal) {
    int n = traversal.length();
    stack<TreeNode*> st;
    int depth = 0, value = 0;

    TreeNode* root = NULL;
    int i = 0;
    while(i < n)
    {
        depth = 0, value = 0;
        while(i < n && traversal[i] == '-')
        {
            depth++;
            i++;
        }

        while(i < n && isdigit(traversal[i]))
        {
            value = (value * 10) + (traversal[i] - '0');
            i++;
        }

        TreeNode* node = new TreeNode(value);
        while(!st.empty() && st.size() > depth) st.pop();

        if(st.empty()) root = node;
        else
        {
            if(!st.top()->left) st.top()->left = node;
            else st.top()->right = node;
        }

        st.push(node);
    }

    return root;
}
