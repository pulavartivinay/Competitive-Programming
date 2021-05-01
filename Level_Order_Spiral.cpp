Question Link: https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1

Solution :
 
     void reverseQueue(queue<Node*>& Queue)
{
    stack<Node*> Stack;
    while (!Queue.empty()) {
        Stack.push(Queue.front());
        Queue.pop();
    }
    while (!Stack.empty()) {
        Queue.push(Stack.top());
        Stack.pop();
    }
}
vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> ans;
    if(root == NULL)
    {
        return ans;
    }
    queue<Node*> li_q;
    stack<Node*> li_s;
    li_q.push(root);
    ans.push_back(root->data);
    int height = 0;
    int count = 0;
    while(!li_q.empty() || !li_s.empty())
    {
        if(height%2 == 0 && !li_q.empty())
        {
            Node *temp = li_q.front();
            li_q.pop();
            if(temp->left != NULL)
            {
                ans.push_back(temp->left->data);
                li_s.push(temp->left);
            }
            if(temp->right != NULL)
            {
                ans.push_back(temp->right->data);
                li_s.push(temp->right);
            }
        }
        else if(height%2 == 1 && !li_s.empty())
        {
            Node *temp = li_s.top();
            li_s.pop();
            if(temp->right != NULL)
            {
                ans.push_back(temp->right->data);
                li_q.push(temp->right);
            }
            if(temp->left != NULL)
            {
                ans.push_back(temp->left->data);
                li_q.push(temp->left);
            }
        }
        count = count + 1;
        if(count == pow(2,height))
        {
            reverseQueue(li_q);
            count = 0;
            height = height + 1;
        }
    }
    return ans;
    
}
