Question Link: https://practice.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1

Solution:
void del(stack<int>& s, int i, int mid)
{
    int pop_elem = s.top();
    s.pop();
    if(i == mid) return;
    del(s, i+1, mid);
    s.push(pop_elem);
}
//Function to delete middle element of a stack.
void deleteMid(stack<int>&s, int sizeOfStack)
{
    // code here.. 
    int len = s.size();
    int mid = ((len+1)/2);
    mid = (len - mid + 1);
    del(s, 1, mid);
}
