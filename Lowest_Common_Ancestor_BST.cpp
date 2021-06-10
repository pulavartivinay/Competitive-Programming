Question Link: https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

Solution Link:

Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   int a = min(n1, n2);
   int b = max(n1, n2);
   int ans = 0;
   if(a < root->data && root->data < b)
   {
       return root;
   }
   else if(root->data < a && root->data < b)
   {
       return LCA(root->right, a, b);
   }
   else if(root->data > a && root->data > b)
   {
       return LCA(root->left, a, b);
   }
   else if(root->data == a && root->data < b)
   {
       return root;
   }
   else if(root->data == b && root->data > a)
   {
       return root;
   }
}
