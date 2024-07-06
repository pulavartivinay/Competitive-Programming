Question Link: https://www.geeksforgeeks.org/problems/fixing-two-swapped-nodes-of-a-bst--170646/1

Solution:
void InOrderBST(Node* root, Node** prev, Node** first, Node** middle, Node** last)
{
    if(!root) return;
    
    InOrderBST(root->left, prev, first, middle, last);
    
    if((*prev) != NULL)
    {
        if((*prev)->data > root->data)
        {
            if((*first) == NULL) 
            {
                *first = *prev;
                *middle = root;
            }
            else *last = root;
        }
    }
    
    *prev = root;
    
    InOrderBST(root->right, prev, first, middle, last);
}
struct Node *correctBST(struct Node *root) {
    // code here
    // prev > curr --> 1st node (prev)
    // prev > curr --> 2nd node (curr)
    // swap(1st node, 2nd node)
    
    Node *prev = NULL, *first = NULL, *middle = NULL, *last = NULL;
    InOrderBST(root, &prev, &first, &middle, &last);
    if(first && last) swap(first->data, last->data);
    else if(first && middle) swap(first->data, middle->data);
    
    return root;
}
