Question Link: https://leetcode.com/problems/implement-queue-using-stacks/description/

Solution:
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty())
        {
            int tmp = s1.top();
            s1.pop();
            s2.push(tmp);
        }

        s1.push(x);

        while(!s2.empty())
        {
            int tmp = s2.top();
            s2.pop();
            s1.push(tmp);
        }
    }
    
    int pop() {
        int tmp = s1.top();
        s1.pop();
        return tmp;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return (s1.empty());
    }
};
