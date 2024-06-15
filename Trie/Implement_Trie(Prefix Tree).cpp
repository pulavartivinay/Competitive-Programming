Question Link: https://leetcode.com/problems/implement-trie-prefix-tree/description/

Solution:
class Trie {
public:
    struct Node
    {
        char c;
        int end;
        Node* children[26];
    };
    Node* getNode(int index)
    {
        Node* node = new Node();
        node->c = 'a'+index;
        node->end = false;
        for(int i=0;i<26;i++) node->children[i] = NULL;

        return node;
    }
    Node* root = NULL;
    Trie() {
        root = getNode(26);
    }
    
    void insert(string word) {
        int len = word.length();
        Node* curr = root;
        for(int i=0;i<len;i++)
        {
            int idx = word[i]-'a';
            if(curr->children[idx] == NULL) curr->children[idx] = getNode(idx);
            curr = curr->children[idx];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        int len = word.length();
        Node* curr = root;
        for(int i=0;i<len;i++)
        {
            int idx = word[i]-'a';
            if(curr->children[idx] == NULL) return false;
            curr = curr->children[idx];
        }
        return (curr->end);
    }
    
    bool startsWith(string prefix) {
        int len = prefix.length();
        Node* curr = root;
        for(int i=0;i<len;i++)
        {
            int idx = prefix[i]-'a';
            if(curr->children[idx] == NULL) return false;
            curr = curr->children[idx];
        }
        return true;
    }
};
