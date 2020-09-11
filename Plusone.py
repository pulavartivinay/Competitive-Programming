/*Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.*/


Solution:
def plusOne(self, A):
        n = len(A)
        A[n-1] += 1
        carry = A[n-1]/10
        A[n-1] = A[n-1] % 10
        for i in range(n-2,-1,-1): 
            if (carry == 1): 
                A[i] += 1
                carry = A[i]/10
                A[i] = A[i] % 10
        if (carry == 1):
            A.insert(0,1)
        count = 0
        for i in range(0,len(A)):
            if A[i] == 0:
                count = count + 1
            else:
                break
        for i in range(0,count):
            A.remove(0)
        return A
