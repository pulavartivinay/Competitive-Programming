Question Link: https://practice.geeksforgeeks.org/problems/implement-queue-using-array/1

Solution:

The structure of the class is
class MyQueue 
{
  private:
      int arr[100005];
      int front;
      int rear;

  public :
      MyQueue(){front=0;rear=0;}
      void push(int);
      int pop();
};
 */

//Function to push an element x in a queue.
void MyQueue :: push(int x)
{
        // Your Code
        arr[rear] = x;
        rear++;
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
        // Your Code
        if(front == rear) return -1;
        return arr[front++];
}
