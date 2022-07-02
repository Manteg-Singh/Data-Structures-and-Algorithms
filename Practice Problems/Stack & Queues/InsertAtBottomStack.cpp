#include <iostream>
#include<stack>
using namespace std;

void  insertAtBottom(int x,stack<int>&s)
{
    if (s.empty())
    {
        s.push(x);

    }
    else
    {
    int temp=s.top();
    s.pop();
    insertAtBottom(x,s);

    s.push(temp);
    }

}


int main()
{
    stack<int> st;
    st.push(1);
    st.push(6);
    st.push(9);
    int x;
    cin>>x;
    insertAtBottom(x,st);

    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    
    



    return 0;
}