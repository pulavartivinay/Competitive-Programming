Question Link: https://practice.geeksforgeeks.org/problems/preorder-to-postorder4423/1

Solution Link: 

   //Function that constructs BST from its preorder traversal.
Node* constructTree(int pre[], int size)
{
    //code here
    if(size == 0) //Empty tree case
    {
        return NULL;
    }
    vector<Node*> li; //vector of nodes
    for(int i=0;i<size;i++)
    {
        li.push_back(newNode(pre[i]));
    }
    Node* root = li[0];
    stack<Node*> li_s; //stack which makes the record of all nodes
    for(int i=0;i<size;i++)
    {
        if(li_s.empty()) //base case (insert the root)
        {
            li_s.push(root);
        }
        else
        {
            if(li_s.top()->data >= li[i]->data) //if the element is lesser then stack top element, then make his left child and push it to the stack.
            {
                li_s.top()->left = li[i];
                li_s.push(li[i]);
            }
            else
            {
                Node* temp = NULL; //if the element is greater then check for the last popped node while searching for element in stack which is greater than current element and then make as right child for the last popped node and push it to the stack.
                while(!li_s.empty() && li_s.top()->data < li[i]->data)
                {
                    temp = li_s.top();
                    li_s.pop();
                }
                temp->right = li[i];
                li_s.push(li[i]);
            }
        }
    }
    return root;
}
