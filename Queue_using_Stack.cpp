Question Link: https://practice.geeksforgeeks.org/problems/queue-using-stack/1#

Solution:

class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) {
        input.push(x);
    }

    int dequeue() {
        while(!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
        if(output.empty())
        {
            return -1;
        }
        else
        {
            int ans = output.top();
            output.pop();
            while(!output.empty())
            {
                input.push(output.top());
                output.pop();
            }
            return ans;
        }
        
    }
};
