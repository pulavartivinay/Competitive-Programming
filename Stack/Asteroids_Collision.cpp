Question Link: https://leetcode.com/problems/asteroid-collision/description/

Solution:
vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> ans;
    int n = asteroids.size();

    stack<int> st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && st.top() > 0 && asteroids[i] < 0
              && (st.top() < abs(asteroids[i]))) st.pop();
        // stack is empty, only one asteroid, no collision
        if(st.empty()) st.push(asteroids[i]);
        // stack top ele is moving left, no collision
        else if(!st.empty() && st.top() < 0) st.push(asteroids[i]);
        // stack top ele and curr asteroid moving right, no collision
        else if(!st.empty() && st.top() > 0 && asteroids[i] > 0) st.push(asteroids[i]);
        // asteroids collision with having same size
        else if(!st.empty() && st.top() == abs(asteroids[i])) st.pop();
    }

    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
