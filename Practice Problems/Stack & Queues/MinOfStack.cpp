#include <iostream>
#include <stack>
using namespace std;

int getMin(stack<int>& s)
{
    int min=s.top();
    while(!s.empty())
    {
        if(s.top()<min)
        {
            min=s.top();
        }
        
        s.pop();
        
        
    }
    
    return min;  
    
}
int main()
{   //18 19 29 15 16
    stack<int> st;
    st.push(0);
    st.push(2);
    st.push(9);
    st.push(9);
    st.push(16);
    cout<<getMin(st);

    return 0;
}