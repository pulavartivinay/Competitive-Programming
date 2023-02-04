Question Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

Solution:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = 0;
        ListNode* tr = head;
        while(tr)
        {
            l++;
            tr = tr->next;
        }
        n = (l - n + 1);
        if(n == 1) return head->next;
        else
        {
            ListNode* prev = NULL;
            ListNode* curr = head;
            for(int i=1;i<n;i++)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
        }
        return head;
    }
};
