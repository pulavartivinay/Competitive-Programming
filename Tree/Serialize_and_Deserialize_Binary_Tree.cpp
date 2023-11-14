Question Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

Solution:
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string msg = "";
        if(!root) return msg;
        queue<TreeNode*> q;

        q.push(root);
        msg += (to_string(root->val) + ',');
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left)
            {
                q.push(node->left);
                msg += (to_string(node->left->val) + ',');
            } else {
                msg += ("$,");
            }

            if(node->right)
            {
                q.push(node->right);
                msg += (to_string(node->right->val) + ',');
            } else {
                msg += ("$,");
            }
        }

        return msg;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;

        cout << data << endl;

        stringstream s(data);
        string node_val;

        queue<TreeNode*> q;
        getline(s, node_val, ',');
        TreeNode* ans = new TreeNode(stoi(node_val));
        q.push(ans);
        while(!q.empty())
        {
            TreeNode* t = q.front();
            q.pop();

            //left child in Binary Tree
            getline(s, node_val, ',');
            if(node_val == "$") t->left = NULL;
            else 
            {
                TreeNode* left = new TreeNode(stoi(node_val));
                t->left = left;
                q.push(left);
            }

            //right child in Binary Tree
            getline(s, node_val, ',');
            if(node_val == "$") t->right = NULL;
            else 
            {
                TreeNode* right = new TreeNode(stoi(node_val));
                t->right = right;
                q.push(right);
            }
        }

        return ans;
    }
};
