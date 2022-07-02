#include <iostream>
#include<stack>
using namespace std;

void ReverseStack(stack<int> &s)
{
    






}

int main()
{
    stack<int> st;
    st.push(3);
    st.push(5);
    st.push(1);
    st.push(6);
    st.push(96);
    ReverseStack(st);
    while (st.size()!=0)
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    

    
    return 0;
}