A prime number is a positive number, which is divisible by exactly two different integers. A digit prime
is a prime number whose sum of digits is also prime. For example the prime number 41 is a digit prime
because 4 + 1 = 5 and 5 is a prime number. 17 is not a digit prime because 1 + 7 = 8, and 8 is not
a prime number. In this problem your job is to find out the number of digit primes within a certain
range less than 1000000.
Input
First line of the input file contains a single integer N (0 < N ≤ 500000) that indicates the total number
of inputs. Each of the next N lines contains two integers t1 and t2 (0 < t1 ≤ t2 < 1000000).
Output
For each line of input except the first line produce one line of output containing a single integer that
indicates the number of digit primes between t1 and t2 (inclusive).
Sample Input
3
10 20
10 100
100 10000
Sample Output
1
10
576

Code: 

#include <iostream>
#include<bits/stdc++.h>
#include<string.h>

using namespace std;

map<int,bool> M {
    {2,true},{3,true},{5,true},{7,true},{11,true},{13,true},{17,true},
    {19,true},{23,true},{29,true},{31,true},{37,true},{41,true},{43,true},{47,true},{53,true}
};

int check_for_digit_prime(long long int hi)
{
    long long int jk = 0;
    while(hi != 0)
    {
        jk = jk + (hi%10);
        hi = hi/10;
    }
    if(M[jk] == true)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool isPrime(long long int n) 
{ 
    // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    // This is checked so that we can skip 
    // middle five numbers in below loop 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (long long int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long int N;
    cin >> N;
    map<long long int,long long int> store;
    store[0] = 0;
    for(long long int j=1;j<1000000;j++)
    {
        if(check_for_digit_prime(j))
        {
            if(isPrime(j))
            {
                store[j] = store[j-1]+1;
            }
            else
            {
                store[j] = store[j-1];
            }
        }
        else
        {
            store[j] = store[j-1];
        }
    }
    for(long long int i=0;i<N;i++)
    {
        long long int a,b;
        cin >> a >> b;
        if(isPrime(a) && check_for_digit_prime(a))
        {
            cout << (store[b] - store[a] + 1) << endl;
        }
        else
        {
            cout << store[b] - store[a] << endl;
        }
    }
	return 0;
}
