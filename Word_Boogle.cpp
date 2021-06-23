Question Link: https://practice.geeksforgeeks.org/problems/72cf44eabd18006810efad06fbb623a0682acee2/1

Solution:

struct Node
    {
        char data;
        struct Node* children[26];
        int leaf;
    };
 
    Node* init(char c)
    {
        Node* temp = new Node;
        temp->data = c;
        for(int k=0;k<26;k++)
        {
            temp->children[k] = NULL;
        }
        temp->leaf = 0;
        return temp;
    }
 
    void DFS(vector<vector<char> >& board, int i, int j, Node* start, bool visited[50][50], string li, unordered_set<string>& ans)
    {
        if(start->leaf == 1)
        {
            ans.insert(li);
        }
        int R = board.size();
        int C = board[0].size();
        visited[i][j] = true;
        for(int m=0;m<26;m++)
        {
            if(start->children[m] != NULL)
            {
                char curr_chr = (char)m + (char)'A';
                if(i-1 >= 0 && j-1 >= 0 && visited[i-1][j-1] == 0 && board[i-1][j-1] == curr_chr)// 1 -> left top
                {
                    DFS(board, i-1, j-1, start->children[m], visited, li + curr_chr, ans);
                }
                if(i-1 >= 0 && j >= 0 && visited[i-1][j] == 0 && board[i-1][j] == curr_chr)// 2 -> top
                {
                    DFS(board, i-1, j, start->children[m], visited, li + curr_chr, ans);
                }
                if(i-1 >= 0 && j+1 < C && visited[i-1][j+1] == 0 && board[i-1][j+1] == curr_chr)// 3 -> right top
                {
                    DFS(board, i-1, j+1, start->children[m], visited, li + curr_chr, ans);
                }
                if(i >= 0 && j-1 >= 0 && visited[i][j-1] == 0 && board[i][j-1] == curr_chr)// 4 -> left
                {
                    DFS(board, i, j-1, start->children[m], visited, li + curr_chr, ans);
                }
                if(i >= 0 && j+1 < C && visited[i][j+1] == 0 && board[i][j+1] == curr_chr)// 5 -> right
                {
                    DFS(board, i, j+1, start->children[m], visited, li + curr_chr, ans);
                }
                if(i+1 < R && j-1 >= 0 && visited[i+1][j-1] == 0 && board[i+1][j-1] == curr_chr)// 6 -> bottom left
                {
                    DFS(board, i+1, j-1, start->children[m], visited, li + curr_chr, ans);
                }
                if(i+1 < R && j >= 0 && visited[i+1][j] == 0 && board[i+1][j] == curr_chr)// 7 -> bottom
                {
                    DFS(board, i+1, j, start->children[m], visited, li + curr_chr, ans);
                }
                if(i+1 < R && j+1 < C && visited[i+1][j+1] == 0 && board[i+1][j+1] == curr_chr)// 8 -> bottom right
                {
                    DFS(board, i+1, j+1, start->children[m], visited, li + curr_chr, ans);
                }
            }
        }
        visited[i][j] = false;
    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	    unordered_set<string> ans;
	    int R = board.size();
	    int C = board[0].size();
	    //Step-1: Trie Creation and insert all the words of dictionary into the Trie
	    Node* root = init('*');
	    for(int i=0;i<(dictionary.size());i++)
	    {
            string curr_str = dictionary[i];
            Node* travel = root;
            for(int j=0;j<(curr_str.length());j++)
            {
                char c = curr_str[j];
	            if(travel->children[c - 'A'] == NULL)
	            {
	                travel->children[c - 'A'] = init(c);
	            }
	            travel = travel->children[c - 'A'];
            }
            travel->leaf = 1;
	    }
	    //Step-2: Now Apply DFS for every cell until we reach the leaf
        for(int i=0;i<R;i++)
	    {
	        for(int j=0;j<C;j++)
	        {
	            bool visited[50][50];
                memset(visited, false, sizeof(visited));
	            char c = board[i][j];
	            if(root->children[c - 'A'] != NULL)
	            {
	                string li = "";
	                li = li + c;
	                DFS(board, i, j, root->children[c - 'A'], visited, li, ans);
	            }
	        }
	    }
        
        vector<string> hi;
	    unordered_set<string>::iterator it;
	    for(it = ans.begin();it != ans.end();it++)
	    {
	        hi.push_back(*it);
	    }
	    return hi;
	}
