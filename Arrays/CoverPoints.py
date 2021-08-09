/*You are in an infinite 2D grid where you can move in any of the 8 directions

 (x,y) to 
    (x+1, y), 
    (x - 1, y), 
    (x, y+1), 
    (x, y-1), 
    (x-1, y-1), 
    (x+1,y+1), 
    (x-1,y+1), 
    (x+1,y-1) 
You are given a sequence of points and the order in which you need to cover the points.. 
Give the minimum number of steps in which you can achieve it. You start from the first point. */

Solution:
def coverPoints(self, A, B):
        points = []
        for i in range(0,len(A)):
            points.append([A[i],B[i]])
        steps = 0
        for i in range(0,len(points)-1):
            a_x = abs(points[i+1][0] - points[i][0])
            a_y = abs(points[i+1][1] - points[i][1])
            steps = steps + max(a_x,a_y)
        return steps
