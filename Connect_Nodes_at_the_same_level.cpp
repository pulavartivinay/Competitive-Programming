Question Link: https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1/

Solution Link:

class Solution
{
    public:
    //Function to connect nodes at same level.
    map<Node*, int> arr;
    void computeHeight(Node* root)
    {
        if(root)
        {
            if(root->left)
            {
                arr[root->left] = arr[root] + 1;
                computeHeight(root->left);
            }
            if(root->right)
            {
                arr[root->right] = arr[root] + 1;
                computeHeight(root->right);
            }
        }
    }
    void connect(Node *root)
    {
       // Your Code Here
      arr[root] = 1;
      computeHeight(root);
      vector<Node*> q;
      q.push_back(root);
      while(q.size() != 0)
      {
          if(q.size() == 1)
          {
              q[0]->nextRight = NULL;
              if(q[0]->left)
              {
                  q.push_back(q[0]->left);
              }
              if(q[0]->right)
              {
                  q.push_back(q[0]->right);
              }
              q.erase(q.begin());
          }
          else if(arr[q[0]] != arr[q[1]])
          {
              q[0]->nextRight = NULL;
              if(q[0]->left)
              {
                  q.push_back(q[0]->left);
              }
              if(q[0]->right)
              {
                  q.push_back(q[0]->right);
              }
              q.erase(q.begin());
          }
          else
          {
              q[0]->nextRight = q[1];
              if(q[0]->left)
              {
                  q.push_back(q[0]->left);
              }
              if(q[0]->right)
              {
                  q.push_back(q[0]->right);
              }
              q.erase(q.begin());
          }
      }
    }    
      
};
