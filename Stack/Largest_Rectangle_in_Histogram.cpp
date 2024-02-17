Question Link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/

Solution:
int largestRectangleArea(vector<int>& heights) {
    int ans = 0;
    int n = heights.size();
    stack<int> st;

    for(int i=0;i<n;i++)
    {
        while(!st.empty() && heights[i] < heights[st.top()]) 
        {
            int curr_bar = heights[st.top()];
            st.pop();
            if(!st.empty()) ans = max(ans, curr_bar * (i - st.top() - 1));
            else ans = max(ans, curr_bar * (i));
        }
        
        st.push(i);
    }

    while(!st.empty()) 
    {
        int curr_bar = heights[st.top()];
        st.pop();
        if (!st.empty()) ans = max(ans, curr_bar * (n - st.top() - 1));
        else ans = max(ans, curr_bar * (n));
    }

    return ans;
}
