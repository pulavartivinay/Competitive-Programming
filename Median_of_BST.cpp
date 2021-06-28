Question Link: https://practice.geeksforgeeks.org/problems/median-of-bst/1#

Solution:

void count_nodes(Node* root, int& k)
{
    if(root)
    {
        count_nodes(root->left, k);
        k = k + 1;
        count_nodes(root->right, k);
    }
}
void medianHelper(Node* &prev, Node* &curr, Node* root, int& a, int& count)
{
    if(root)
    {
        medianHelper(prev, curr, root->left, a, count);
        if(count < a)
        {
            prev = root;
            count = count + 1;
        }
        else if(count == a)
        {
            curr = root;
            count = count + 1;
            return;
        }
        else
        {
            return;
        }
        medianHelper(prev, curr, root->right, a, count);
    }
    else
    {
        return;
    }
}
float findMedian(struct Node *root)
{
      //Code here
      int total_nodes = 0;
      count_nodes(root, total_nodes);
      Node* prev = NULL;
      Node* curr = NULL;
      int a = ceil(total_nodes/2) + 1;
      int count = 1;
      medianHelper(prev, curr, root, a, count);
      if(total_nodes&1) return curr->data*1.0;
      return (((prev->data + curr->data)*1.0)/(2*1.0));
}
