Question Link: https://www.naukri.com/code360/problems/complete-string_2687860?leftPanelTabValue=PROBLEM

Solution:
#include <bits/stdc++.h> 
struct Node
{
    char c;
    bool end;
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

void insert(Node* curr, string& word)
{
    int len = word.length();
    for(int i=0;i<len;i++)
    {
        int idx = word[i]-'a';
        if(curr->children[idx] == NULL) curr->children[idx] = getNode(idx);
        curr = curr->children[idx];
    }
    curr->end = true;
}

bool isCompleteString(Node* curr, string& word)
{
    int len = word.length();
    for(int i=0;i<len;i++)
    {
        int idx = word[i]-'a';
        curr = curr->children[idx];
        if(curr->end == false) return false;
    }

    return true;
}

string completeString(int n, vector<string> &a){
    // Write your code here.
    string ans = "";
    sort(a.begin(), a.end());
    Node* root = getNode(26);
    for(int i=0;i<a.size();i++) insert(root, a[i]);

    for(int i=0;i<a.size();i++)
    {
        if(isCompleteString(root, a[i]) && a[i].length() > ans.length()) ans = a[i];
    }

    return ((ans != "") ? ans : "None");
}
