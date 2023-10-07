Question Link: https://leetcode.com/problems/implement-stack-using-queues/

Solution:
class MyStack {
    queue<int> q;
public:
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
        int n = q.size();
        for(int i=1;i<n;i++)
        {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
    }
    
    int pop() {
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.size() == 0) return true;
        else return false;
    }
};
