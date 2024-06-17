Question Link: https://www.geeksforgeeks.org/problems/connect-nodes-at-same-level/1

Solution:
void connect(Node *root)
{
   // Your Code Here
   queue<pair<Node*, int>> q;
   q.push({root, 1});
   Node* prev = NULL;
   int tree_lvl = 0;
   
   while(!q.empty())
   {
       pair<Node*, int> p = q.front();
       q.pop();
       Node* curr = p.first;
       int curr_lvl = p.second;
       
       if(tree_lvl != curr_lvl) 
       {
           prev = NULL;
           tree_lvl = curr_lvl;
       }
       else
       {
           // set curr to prev nextRight node
           prev->nextRight = curr;
       }
       prev = curr;
       
       if(curr->left) q.push({curr->left, curr_lvl+1});
       if(curr->right) q.push({curr->right, curr_lvl+1});
   }
}
