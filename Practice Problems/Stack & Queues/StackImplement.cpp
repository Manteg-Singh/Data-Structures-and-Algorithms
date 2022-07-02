#include <iostream>
using namespace std;
#define MaxSizeOfStack 100
class stack
{
    public:
    int* arr;
    int top=-1;
    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout<<arr[i]<<" ";
        }
        
    }

    stack()
    {
        arr=new int[MaxSizeOfStack];
    }
    void push(int key)
    {
        if (top==MaxSizeOfStack-1  )
        {
            cout<<"Stack Overflow"<<endl;
        }
        else
        {
            top++;
            arr[top]=key;
        }
        
    }

    void pop()
    {
        if (top==-1)
        {
            cout<<"Stack Underflow"<<endl;
            
        }
        else
        {
            top--;
        }
        
    }

    void Top()
    {
        if (top==-1)
        {
            cout<<"Stack Empty"<<endl;
            
            
        }
        else
        {
            cout<< arr[top];
        }
        
        
        
        
       
    }


};




int main()
{
    stack s1;
    s1.pop();
    s1.push(3);
    s1.push(2);
    s1.push(1);
    s1.display();
    s1.pop();
    cout<<endl;
    s1.Top();

    
    return 0;
}