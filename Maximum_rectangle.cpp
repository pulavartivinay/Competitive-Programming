Question Link: https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1

Solution Link: 

   long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<long long int> li_s;
        li_s.push(0);
        //left consecutive part
        vector<long long int> left;
        left.push_back(1);
        for(int i=1;i<n;i++)
        {
            while(!li_s.empty() && arr[li_s.top()] >= arr[i])
            {
                li_s.pop();
            }
            if(li_s.empty())
            {
                left.push_back(i+1);
            }
            else
            {
                left.push_back(i - li_s.top());
            }
            li_s.push(i);
        }
        
        //right consecutive part
        stack<long long int> qi_s;
        qi_s.push(0);
        
        vector<int> temp(arr, arr + n);
        reverse(temp.begin(), temp.end());
        
        vector<long long int> right;
        right.push_back(1);
        for(int i=1;i<n;i++)
        {
            while(!qi_s.empty() && temp[qi_s.top()] >= temp[i])
            {
                qi_s.pop();
            }
            if(qi_s.empty())
            {
                right.push_back(i+1);
            }
            else
            {
                right.push_back(i - qi_s.top());
            }
            qi_s.push(i);
        }
        reverse(right.begin(), right.end());
        
        // for(int i=0;i<n;i++)
        // {
        //     cout << left[i] << " ";
        // }
        
        long long int max_area = 0;
        for(int j=0;j<n;j++)
        {
            max_area = max(max_area, arr[j]*(left[j] + right[j] - 1));
        }
        
        return max_area;
        
    }
