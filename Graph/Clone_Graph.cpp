Question Link: https://leetcode.com/problems/clone-graph/description/

Solution:
class Solution {
public:
    unordered_map<int, Node*> mp;
    Node* cloneGraph(Node* node) {
        Node* ans = NULL;
        if(node == NULL) return ans;

        ans = new Node(node->val);
        mp[node->val] = ans;
        int n = node->neighbors.size();
        for(int i=0;i<n;i++)
        {
            Node* adj = node->neighbors[i];
            if(mp[adj->val] == NULL) mp[adj->val] = cloneGraph(adj);

            ans->neighbors.push_back(mp[adj->val]);
        }
        return ans;
    }
};
