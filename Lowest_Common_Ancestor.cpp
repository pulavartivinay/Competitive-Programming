Question Link: https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1#


Solution :
    
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
    
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here
      for(int i=0;i<100000;i++)
      {
          parent[i] = 0;
          height[i] = 0;
      }
      parent[root->data] = root->data;
      height[root->data] = 1;
      assign_parent(root);
      while(height[n1] < height[n2])
      {
          n2 = parent[n2];
      }
      while(height[n1] > height[n2])
      {
          n1 = parent[n1];
      }
      while(n1 != n2)
      {
         n1 = parent[n1];
         n2 = parent[n2];
      }
      Node* ans = new Node;
      ans->data = n1;
      ans->left = NULL;
      ans->right = NULL;
      return ans;
    }
