Question Link: https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1

Solution:

int getCount(Node *root, int l, int h)
{
  // your code goes here  
  if(root)
  {
      if(l <= root->data && root->data <= h)
      {
          return 1 + getCount(root->left, l, h) + getCount(root->right, l, h);
      }
      else if(l > root->data)
      {
          return getCount(root->right, l, h);
      }
      else if(root->data > h)
      {
          return getCount(root->left, l ,h);
      }
  }
}
