Question Link: https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1#


Solution:

    vector<string> generate(int N)
  {
    // Your code here
    vector<string> li;
    for(int i=1;i<=N;i++)
    {
        string binary = bitset<20>(i).to_string();
        binary.erase(0, binary.find_first_not_of('0'));
        li.push_back(binary);
    }
    return li;
  }

                
 
