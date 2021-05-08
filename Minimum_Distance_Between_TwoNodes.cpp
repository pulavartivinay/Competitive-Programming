
Question Link: https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

Solution Link: 

    int parent[100000];
int height[100000];
void assign_parent(Node* root)
{
    if(root != NULL)
    {
        if(root->left != NULL)
        {
            parent[root->left->data] = root->data;
            height[root->left->data] = height[root->data] + 1;
            assign_parent(root->left);
        }
        if(root->right != NULL)
        {
            parent[root->right->data] = root->data;
            height[root->right->data] = height[root->data] + 1;
            assign_parent(root->right);
        }
    }
}

int findDist(Node* root, int a, int b) {
    // Your code here
     for(int i=0;i<100000;i++)
      {
          parent[i] = 0;
          height[i] = 0;
      }
      parent[root->data] = root->data;
      height[root->data] = 1;
      assign_parent(root);
      int h_n1 = height[a];
      int h_n2 = height[b];
      while(height[a] < height[b])
      {
          b = parent[b];
      }
      while(height[a] > height[b])
      {
          a = parent[a];
      }
      while(a != b)
      {
         a = parent[a];
         b = parent[b];
      }
      int ans = abs(h_n1 - height[a]) + abs(h_n2 - height[a]);
      return ans;
    
}
