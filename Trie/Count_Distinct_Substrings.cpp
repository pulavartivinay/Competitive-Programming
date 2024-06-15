Question Link: https://www.naukri.com/code360/problems/count-distinct-substrings_985292?leftPanelTabValue=PROBLEM

Solution:
struct Node{
    char c;
    int end;
    Node* children[26];
};

Node* getNode(int idx)
{
    Node* node = new Node();
    node->c = 'a'+idx;
    node->end = false;
    for(int i=0;i<26;i++) node->children[i] = NULL;

    return node;
}

int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    Node* root = getNode(26);
    int ans = 1; // empty string
    for(int i=0;i<s.length();i++)
    {
        Node* curr = root;
        for(int j=i;j<s.length();j++)
        {
            int idx = s[j]-'a';
            if (curr->children[idx] == NULL) {
              curr->children[idx] = getNode(idx);
              ans++;
            }
            curr = curr->children[idx];
        }
    }

    return ans;
}
