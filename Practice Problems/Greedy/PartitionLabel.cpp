#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lastOccur(string s, char a)
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == a)
                ans = i;
        }
        return ans;
    }

    vector<int> partitionLabels(string s)
    {
        int i = 0;
        int res = 0;
        vector<int> ans;
        while (i < s.size())
        {
            int maxi = s[i];
            int maxind = lastOccur(s, s[i]);
            for (int j = i; j < maxind; j++)
            {
                // if(lastOccur(s,s[j])>maxind)
                //     maxind=lastOccur(s,s[j]);
                i++;
            }
            
            ans.push_back(i);
        }
        return ans;
    }
};
int main()
{

    return 0;
}