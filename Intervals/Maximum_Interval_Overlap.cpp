Question Link: https://www.geeksforgeeks.org/problems/maximum-intervals-overlap5708/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

Solution:
vector<int> findMaxGuests(int Entry[], int Exit[], int N)
{
   // Your code goes here
   sort(Entry, Entry+N);
   sort(Exit, Exit+N);
   
   int guests = 1, max_guests = 1, min_time = Entry[0];
   int i = 1, j = 0;
   
   while(i < N && j < N)
   {
       if(Entry[i] <= Exit[j])
       {
           guests++;
           if(guests > max_guests)
           {
               max_guests = guests;
               min_time = Entry[i];
           }
           i++;
       }
       else
       {
           guests--;
           j++;
       }
   }
   
   return {max_guests, min_time};
}
