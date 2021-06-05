Question Link: https://practice.geeksforgeeks.org/problems/node-at-distance/1

Solution Link:

map<Node*, Node*> parent;
vector<Node*> leaves;
void findLeaves(Node * root)
{
    if(root)
    {
        if(root->left == NULL && root->right == NULL)
        {
            leaves.push_back(root);
        }
        if(root->left)
        {
            parent[root->left] = root;
            findLeaves(root->left);
        }
        if(root->right)
        {
            parent[root->right] = root;
            findLeaves(root->right);
        }
    }
}
int printKDistantfromLeaf(Node* root, int k)
{
	//Add your code here. 
	parent[root] = NULL;
	findLeaves(root);
	set<Node*> s;
	int n = leaves.size();
	for(int i=0;i<n;i++)
	{
	    Node* temp = leaves[i];
	    int hi = 0;
	    while(hi < k && temp != NULL)
	    {
	        temp = parent[temp];
	        hi++;
	    }
	    if(temp != NULL)
	    {
	        s.insert(temp);
	    }
	}
	leaves.clear();
	parent.clear();
	return s.size();
}
