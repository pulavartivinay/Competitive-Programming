Question Link: https://www.geeksforgeeks.org/problems/shuffle-integers2401/1

Solution:
void shuffleArray(int arr[],int n)
	{
	    // Your code goes here
	    for(int i=0;i<(n/2);i++) {
            arr[i] = ((arr[i] << 10) | arr[i+(n/2)]);
        }
        
        int i = (n/2)-1;
        int j = n-1;
        while(i >= 0 && j >= 0) {
            long long int neg = ((1 << 10) - 1);
            arr[j] = (arr[i] & neg); // extract b
            arr[j-1] = (arr[i] >> 10); // extract a
            j -= 2;
            i--;
        }
	}
