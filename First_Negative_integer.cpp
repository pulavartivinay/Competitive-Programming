Question Link: https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#

Solution Link: 

  vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) 
    {
        vector<long long int> li;
        if(K == 1)
        {
            for(long long int i=0;i<N;i++)
            {
                if(A[i] >= 0)
                {
                    li.push_back(0);
                }
                else
                {
                    li.push_back(A[i]);
                }
            }
            return li;
        }
        else
        {
            long long int first,second;
            first = 0;
            second = 0;
            int count = 0;
            for(long long int i=0;i<K;i++)
            {
                if(A[i] < 0 && count == 0)
                {
                    count++;
                    first = A[i];
                }
                else if(A[i] < 0 && count == 1)
                {
                    count++;
                    second = A[i];
                    break;
                }
            }
            li.push_back(first);
            for(long long int i=1;i<=(N-K);i++)
            {
                if(first == 0 && second == 0)
                {
                    if(A[i+K-1] < 0)
                    {
                        first = A[i+K-1];
                    }
                }
                else if(first != A[i-1])
                {
                    if(second == 0 && A[i+K-1] < 0)
                    {
                        second = A[i+K-1];
                    }
                }
                else if(first == A[i-1])
                {
                    if(second == 0)
                    {
                        if(A[i+K-1] < 0)
                        {
                            first = A[i+K-1];
                            second = 0;
                        }
                        else
                        {
                            first = 0;
                            second = 0;
                        }
                    }
                    else
                    {
                        int temp1 = 0;
                        first = 0;
                        second = 0;
                        for(long long int j=i;j<(i+K);j++)
                        {
                            if(A[j] < 0 && temp1 == 0)
                            {
                                temp1++;
                                first = A[j];
                            }
                            else if(A[j] < 0 && temp1 == 1)
                            {
                                temp1++;
                                second = A[j];
                                break;
                            }
                        }
                    }
                }
                li.push_back(first);
            }
            return li;
        }                                               
 }
