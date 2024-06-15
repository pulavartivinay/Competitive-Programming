Question Link: https://www.naukri.com/code360/problems/implement-trie_1387095?leftPanelTabValue=PROBLEM

Solution:
class Trie{

    public:
    struct Node
    {
        char c;
        bool end;
        int cnt;
        int word_cnt;
        Node* children[26];
    };
    Node* getNode(int idx)
    {
        Node* node = new Node();
        node->c = 'a'+idx;
        node->end = false;
        node->cnt = 0;
        node->word_cnt = 0;
        for(int i=0;i<26;i++) node->children[i] = NULL;

        return node;
    }

    Node* root = NULL;
    Trie(){
        root= getNode(26);
    }

    void insert(string &word){
        int len = word.length();
        Node* curr = root;
        for(int i=0;i<len;i++)
        {
            int idx = word[i]-'a';
            if(curr->children[idx] == NULL) curr->children[idx] = getNode(idx);
            curr = curr->children[idx];
            curr->cnt++;
        }
        curr->end = true;
        curr->word_cnt++;
    }

    int countWordsEqualTo(string &word){
        int len = word.length();
        Node* curr = root;
        for(int i=0;i<len;i++)
        {
            int idx = word[i]-'a';
            if(curr->children[idx] == NULL) return 0;
            curr = curr->children[idx];
        }
        return ((curr->end) ? curr->word_cnt : 0);
    }

    int countWordsStartingWith(string &word){
        int len = word.length();
        Node* curr = root;
        for(int i=0;i<len;i++)
        {
            int idx = word[i]-'a';
            if(curr->children[idx] == NULL) return 0;
            curr = curr->children[idx];
        }
        return curr->cnt;
    }

    void free_trie(Node* curr)
    {
        if(curr)
        {
            for(int i=0;i<26;i++)
            {
                if(curr->children[i]) free_trie(curr->children[i]);
                curr->children[i] = NULL;
            }
            free(curr);
        }
    }

    void erase(string &word){
        int len = word.length();
        Node* curr = root;
        for(int i=0;i<len;i++)
        {
            int idx = word[i]-'a';
            if(curr->children[idx] == NULL) return;
            curr = curr->children[idx];
            curr->cnt--;
            if (curr->cnt == 0) {
              free_trie(curr);
              curr = NULL;
              return;
            }
        }
        curr->end = false;
        curr->word_cnt--;
    }
};
