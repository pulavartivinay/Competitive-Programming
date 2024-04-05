Question Link: https://leetcode.com/problems/merge-k-sorted-lists/description/?envType=list&envId=xlepm8xi

Solution:
class Solution {
public:
    struct comp
    {
        bool operator()(ListNode* l1, ListNode* l2)
        {
            return (l1->val >= l2->val);
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        ListNode *ans = NULL, *tr = NULL;

        for(int i=0;i<n;i++)
        {
            if(lists[i]) pq.push(lists[i]);
        }

        while(!pq.empty())
        {
            ListNode *curr = pq.top();
            pq.pop();

            if(!tr) {
                ans = curr;
                tr = ans;
            } else {
                tr->next = curr;
                tr = tr->next;
            }

            if(curr->next) pq.push(curr->next);
        }

        return ans;
    }
};
