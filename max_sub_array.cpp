Question link: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1#

Solution:

vector <int> max_of_subarrays(int *arr, int n, int k){
        // your code here
        vector<int> li;
        if(k == 1)
        {
            for(int i=0;i<n;i++)
            {
                li.push_back(arr[i]);
            }
        }
        else
        {
            vector<int> temp;
            int first_max = 0;
            int second_max = 0;
            for(int i=0;i<k;i++)
            {
                if(arr[i] >= first_max)
                {
                    second_max = first_max;
                    first_max = arr[i];
                }
                else if(arr[i] >= second_max)
                {
                    second_max = arr[i];
                }
            }
            li.push_back(first_max);
            for(int i=k;i<n;i++)
            {
                if(first_max != arr[i-k])
                {
                    if(arr[i] >= first_max)
                    {
                        second_max = first_max;
                        first_max = arr[i];
                    }
                    else if(arr[i] >= second_max)
                    {
                        second_max = arr[i];
                    }
                    li.push_back(first_max);
                }
                else
                {
                    if(arr[i] >= second_max)
                    {
                        first_max = arr[i];
                    }
                    else
                    {
                        first_max = 0;
                        second_max = 0;
                        for(int j=i;j>(i-k);j--)
                        {
                            if(arr[j] >= first_max)
                            {
                                second_max = first_max;
                                first_max = arr[j];
                            }
                            else if(arr[j] >= second_max)
                            {
                                second_max = arr[j];
                            }
                        }
                    }
                    li.push_back(first_max);
                }
            }
        }
        return li;
    }
