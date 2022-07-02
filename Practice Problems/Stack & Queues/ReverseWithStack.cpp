#include <iostream>
#include<stack>
#include<string>

using namespace std;

void reverse(string S, int len)
{
    stack<char> ch;
    for (int i = 0; i < len; i++)
    {
        ch.push(S[i]);
    }
    for (int i = 0; i < len; i++)
    {
        S[i]=ch.top();
        ch.pop();
    }
    cout<<S;
    
   
}
int main()
{
    string str="Manteg";
    
   reverse(str,str.length());
   
    
    return 0;
}