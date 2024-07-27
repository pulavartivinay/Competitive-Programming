Question: https://leetcode.com/problems/delete-node-in-a-linked-list/description/

Solution:
void deleteNode(ListNode* node)
{
    ListNode* tmp = node->next;
    node->val = tmp->val;
    node->next = tmp->next;
    delete tmp;
}
