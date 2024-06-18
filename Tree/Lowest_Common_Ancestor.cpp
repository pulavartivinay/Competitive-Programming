Question Link: https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

Solution:
Node* lca(Node* root ,int n1 ,int n2 )
{
   //Your code here
   Node *l = NULL, *r = NULL;
   if(root->data == n1 || root->data == n2) return root;
   if(root->left) l = lca(root->left, n1, n2);
   if(root->right) r = lca(root->right, n1, n2);
   
   if(l && r) return root;
   else if(l && !r) return l;
   else if(!l && r) return r;
   else return NULL;
}
