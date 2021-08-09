Question Link: https://www.hackerrank.com/contests/inter-iit-coding-contest-2021/challenges/astro-avengers

Solution:

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long int n,k;
    cin >> n >> k;
    priority_queue<long long int> pq;
    long long int mod = pow(10,9) + 7;
    unordered_map<long long int, long long int> li;
    for(long long int i=0;i<n;i++)
    {
        long long int temp;
        cin >> temp;
        li[temp] = li[temp] + 1;
        pq.push(temp);
    }
    long long int ans = 0;
    if(n <= k)
    {
        ans = ans + n;
    }
    else
    {
        ans = ans + k;
        while(k > 0)
        {
            li[pq.top()] = li[pq.top()] - 1;
            pq.pop();
            k = k - 1;
        }
        while(pq.top() > 1)
        {
            long long int t = pq.top();
            if(li[t] != 0)
            {
                pq.pop();
                long long int m = floor(sqrt(t));
                if(li[m] == 0)
                {
                    pq.push(m);
                }
                li[m] = li[m] + li[t]*m;
                ans = ans + li[t];
                li[t] = 0;
            }
            else
            {
                pq.pop();
            }
        }
    }
    cout << (ans%mod) << endl;
    
    return 0;
}
