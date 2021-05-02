Question Link: https://practice.geeksforgeeks.org/problems/circular-tour/1#

Solution :

    int tour(petrolPump p[],int n)
    {
       //Your code here
       int ans = -1;
       for(int i=0;i<n;i++)
       {
           if(p[i].petrol > p[i].distance)
           {
               int total_petrol = 0;
               int total_distance = 0;
               for(int j=i;j<(i+n);j++)
               {
                   total_petrol = total_petrol + p[j%n].petrol;
                   total_distance = total_distance + p[j%n].distance;
                   if(total_petrol < total_distance)
                   {
                       break;
                   }
               }
               if(total_petrol >= total_distance)
               {
                   ans = i;
                   break;
               }
           }
       }
       return ans;
    }
