Question Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

Solution:
Node* connect(Node* root) {
    if(!root) return NULL;

    queue<pair<Node*, int>> q;
    q.push({root, 1});
    while(!q.empty())
    {
        // number of elements in current level
        int len = q.size();
        for(int i=0;i<len;i++)
        {
            pair<Node*, int> p = q.front();
            Node* curr_node = p.first;
            int curr_lvl = p.second;
            q.pop();

            if(i == len-1) curr_node->next = NULL;
            else curr_node->next = q.front().first;

            if(curr_node->left) q.push({curr_node->left, curr_lvl+1});
            if(curr_node->right) q.push({curr_node->right, curr_lvl+1});
        }
    }
    return root;
}
