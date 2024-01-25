Question Link: https://leetcode.com/problems/copy-list-with-random-pointer/description/

Solution:
Node* copyRandomList(Node* head) {
    Node* ans = NULL;
    if(!head) return ans;

    unordered_map<Node*, int> mp;
    ans = new Node(head->val);
    int cnt = 0;
    mp[head] = ++cnt;

    Node *tmp = head->next, *tr = ans;
    while(tmp)
    {
        tr->next = new Node(tmp->val);
        mp[tmp] = ++cnt;
        tr = tr->next;
        tmp = tmp->next;
    }

    tmp = head, tr = ans;
    while(tmp)
    {
        if(!tmp->random) tr->random = NULL;
        else
        {
            int ind = mp[tmp->random], ind_cnt = 1;
            Node* tr_ind = ans;
            while(ind_cnt < ind)
            {
                tr_ind = tr_ind->next;
                ind_cnt++;
            }
            tr->random = tr_ind;
        }
        
        tr = tr->next;
        tmp = tmp->next;
    }

    return ans;
}
