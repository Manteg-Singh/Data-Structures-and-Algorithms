#include <iostream>
#include<list>
using namespace std;
class Solution {
public:
    int findTheWinner(int n, int k) {
        list<int> li;
        for (int i = 1; i <= n; i++)
        {
            li.push_back(i);
        }
        int j=0;
        list<int>:: iterator it=li.begin(); 
        list<int>:: iterator en=li.begin(); 
        
        while (li.size()!=1)
        {
            en=li.begin();
            j=(j+(k-1))%li.size();
            advance(en,j);
            li.erase(en);
            
            

            
        }
        return *li.begin();
    }
};
// int main()
// {
//     int k=findTheWinner(5,2);
//    cout<<k;
    
//     return 0;
// }