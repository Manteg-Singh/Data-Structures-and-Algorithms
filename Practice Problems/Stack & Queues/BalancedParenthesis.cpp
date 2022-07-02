#include <iostream>
#include<cmath>
#include<stack>
using namespace std;


int main()
{
    string s;int f=0;
    stack<int> stk;
    cin>>s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]=='(')
        {
            stk.push(s[i]);
        }
        else 
        {
            if (!stk.empty())
            {
                stk.pop();
            }
            else
            {
                f=1;
                cout<<"UNBALANCED"<<endl;
                break;
            }
            
            
            
        }
        
    }
    if (f==0)
    {if (stk.empty())
    {
        cout<<"BALANCED"<<endl;
    }
    else
    {
        cout<<"UNBALANCED"<<endl;
    }
    }
    

    
    return 0;
}