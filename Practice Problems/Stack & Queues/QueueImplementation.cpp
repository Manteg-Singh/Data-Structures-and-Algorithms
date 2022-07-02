#include <iostream>
#define Max 1000
using namespace std;
class queue
{
    int front,rear;
    int* arr;
    public:
    queue()
    {
        front=-1;
        rear=-1;
        arr=new int[Max];

    }
    void Enqueue(int key)
    {
        if (isFull())
        {
            cout<<"Queue Full"<<endl;

        }
        else if(front==-1)
        {
            front =0;
            rear=0;
            arr[rear]=key;
        }
        else
        {
            rear++;
            arr[rear]=key;
        }       
    }
    void Dequeue()
    {
        if (front==-1)
        {
            cout<<"Queue Empty";
        }

        else if (front==rear)
        {
            front = -1;
            rear=-1;

        }
        else
        {
            front++;
        }
       
    }
    bool isEmpty()
    {
        if ((front==-1 ))
        {
                return true;
        }
        else
        {
            return false;
        }
        
    }
    bool isFull()
    {
        if (rear==Max-1 )
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    void diplay()
    {
        for (int i = front; i <= rear; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }



};

int main()
{
    queue q;
    q.Enqueue(4);
    q.Enqueue(6);
    q.Enqueue(9);
    q.Dequeue();
    q.diplay();
    



    
    return 0;
}