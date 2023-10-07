Question Link: https://www.codingninjas.com/studio/problems/stack-implementation-using-array_3210209?leftPanelTab=0

Solution:
class Stack {
    
public:
    int *arr;
    int curr, size;
    
    Stack(int capacity) {
        // Write your code here.
        arr = (int *)calloc(capacity, sizeof(int));
        curr = 0;
        size = capacity;
    }

    void push(int num) {
        // Write your code here.
        if(!isFull()) arr[curr++] = num;
    }

    int pop() {
        // Write your code here.
        if(isEmpty()) return -1;

        int ans = top();

        arr[--curr] = 0;
        return ans;
    }
    
    int top() {
        // Write your code here.
        if(isEmpty()) return -1;
        return arr[curr-1];
    }
    
    int isEmpty() {
        // Write your code here.
        if(curr == 0) return 1;
        else return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(curr == size) return 1;
        else return 0;
    }
    
};
