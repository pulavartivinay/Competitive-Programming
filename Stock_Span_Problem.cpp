Question Link: https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

Solution Link:

vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> ans;
       ans.push_back(1);
       unordered_map<int, int> m;
       stack<int> s;
       s.push(price[0]);
       m[price[0]] = 1;
       for(int i=1;i<n;i++)
       {
           int ele = price[i];
           int count = 1;
           while(!s.empty() && s.top() <= ele)
           {
               count = count + m[s.top()];
               s.pop();
           }
           s.push(ele);
           m[price[i]] = count;
           ans.push_back(count);
       }
       return ans;
    }
