Question Link: https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1

Solution:
Node* insert(Node* root, int data) {
        // Your code goes here
        if(!root) return new Node(data);
        
        if(root->data < data) root->right = insert(root->right, data);
        else if(data < root->data) root->left = insert(root->left, data);
        
        return root;
}
