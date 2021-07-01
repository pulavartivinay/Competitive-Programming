Question Link: https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1/?company[]=Amazon&company[]=Amazon&problemType=functional&page=1&sortBy=submissions&query=company[]AmazonproblemTypefunctionalpage1sortBysubmissionscompany[]Amazon

Solution:

void rearrange(int arr[], int n) {
    // code here
    vector<int> pos;
    vector<int> neg;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(arr[i] >= 0)
        {
            pos.push_back(arr[i]);
        }
        else
        {
            neg.push_back(arr[i]);
        }
    }
    int i=0;
    int j=0;
    int count = 0;
    while(i < pos.size() && j < neg.size())
    {
        if(count%2 == 0)
        {
            ans.push_back(pos[i]);
            i = i + 1;
        }
        else
        {
            ans.push_back(neg[j]);
            j = j + 1;
        }
        count = count + 1;
    }
    while(i < pos.size())
    {
        ans.push_back(pos[i]);
        i = i + 1;
    }
    while(j < neg.size())
    {
        ans.push_back(neg[j]);
        j = j + 1;
    }
    for(int i=0;i<n;i++)
    {
        arr[i] = ans[i];
    }
}
