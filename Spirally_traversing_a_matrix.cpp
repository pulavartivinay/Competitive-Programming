Question Link: https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1#

Solution Link:

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> ans;
        int top = -1;
        int right = c;
        int bottom = r;
        int left = -1;
        //triggers
        int top_trigger = 1;
        int right_trigger = 0;
        int bottom_trigger = 0;
        int left_trigger = 0;
        while(1)
        {
            if(top_trigger)
            {
                for(int i=(left+1);i<right;i++)
                {
                    ans.push_back(matrix[top+1][i]);
                }
                top = top + 1;
                top_trigger = 0;
                if(top < bottom-1)
                {
                    right_trigger = 1;
                }
                else
                {
                    break;
                }
            }
            else if(right_trigger)
            {
                for(int i=(top+1);i<bottom;i++)
                {
                    ans.push_back(matrix[i][right-1]);
                }
                right = right - 1;
                right_trigger = 0;
                if(left < right-1)
                {
                    bottom_trigger = 1;
                }
                else
                {
                    break;
                }
            }
            else if(bottom_trigger)
            {
                for(int i=(right-1);i>left;i--)
                {
                    ans.push_back(matrix[bottom-1][i]);
                }
                bottom = bottom - 1;
                bottom_trigger = 0;
                if(top < bottom-1)
                {
                    left_trigger = 1;
                }
                else
                {
                    break;
                }
            }
            else if(left_trigger)
            {
                for(int i=(bottom-1);i>top;i--)
                {
                    ans.push_back(matrix[i][left+1]);
                }
                left = left + 1;
                left_trigger = 0;
                if(left < right-1)
                {
                    top_trigger = 1;
                }
                else
                {
                    break;
                }
            }
        }
        return ans;
    }
