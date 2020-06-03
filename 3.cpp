/**
There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

 

Example 1:

Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
 

Note:

1 <= costs.length <= 100
It is guaranteed that costs.length is even.
1 <= costs[i][0], costs[i][1] <= 1000
*/

 struct cost{
      int a;
      int b;
    }; 

 bool compare(cost obj1,cost obj2)
    {
        return (abs(obj1.a-obj1.b)>abs(obj2.a-obj2.b));
    }

class Solution {
public:
   
    int twoCitySchedCost(vector<vector<int>>& costs) {
        struct cost arr[costs.size()];
        for(int i =0;i<costs.size();i++)
        {
            arr[i].a = costs[i][0];
            arr[i].b = costs[i][1];
        }
        
        sort(arr,arr+costs.size(),compare);
        int counta=0;
        int countb=0;
        int n = costs.size()/2;
        int sum=0;
        for(int i =0;i<costs.size();i++)
        {
            if(arr[i].a<arr[i].b && counta<n)
            {
                sum=sum+arr[i].a;
                counta++;
            }
            else if(countb<n)
            {
                sum= sum+ arr[i].b;
                countb++;
            }
            else{
                 sum=sum+arr[i].a;
                 counta++;
            }
        }
        return sum;
    }
    
   
};