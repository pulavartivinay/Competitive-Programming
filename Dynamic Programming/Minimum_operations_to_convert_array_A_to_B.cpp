Question Link: https://practice.geeksforgeeks.org/problems/minimum-insertions-to-make-two-arrays-equal/1#

Solution:

 int lis(vector<int> v)
 {
     vector<int> lis;

     for(int i=0;i<v.size();i++)
     {
          auto it = lower_bound(lis.begin(), lis.end(), v[i]);
         if(it!=lis.end()) *it=v[i];
         else lis.push_back(v[i]);
     }
     return lis.size();
 }
 
int minInsAndDel(int A[], int B[], int N, int M) 
{
    // code here
    vector<int> v;
    unordered_set<int> s;

    for(int i=0;i<M;i++)
    {
        s.insert(B[i]);
    }

    for(int i=0;i<N;i++)
    {
        if(s.find(A[i])!=s.end()) v.push_back(A[i]);
    }

    int LCS=lis(v);

    return N+M-(2*LCS);
}
