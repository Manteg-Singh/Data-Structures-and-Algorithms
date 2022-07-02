#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:

    int firstUniqChar(string s) {
        vector<int>ans(26,0);
        for (int i = 0; i < s.size(); i++)
        {
            ans[s[i]-97]++;
            
        }
        for (int i = 0; i <s.size() ; i++)
        {
            if (ans[s[i]]==1)
            {
                return i;
            }
            
        }
        return -1;
        
    }
};
int main()
{
    
    return 0;
}