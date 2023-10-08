Question Link: https://www.codingninjas.com/studio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&leftPanelTab=0

Solution:
void insertStack(stack<int> &st, int num)
{
	if(st.empty() || num >= st.top())
	{
		st.push(num);
		return;
	}

	int top = st.top();
	st.pop();
	insertStack(st, num);
	st.push(top);
}

void sortStack(stack<int> &st)
{
	// Write your code here
	if(!st.empty())
	{
		int top = st.top();
		st.pop();
		sortStack(st);
		insertStack(st, top);
	}
}
