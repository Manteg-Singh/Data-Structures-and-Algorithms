#include <iostream>

using namespace std;
class MyCircularDeque {
    int front,rear,size;
    int* arr;
public:
    MyCircularDeque(int k) {
        front=-1;
        rear=-1;
        arr=new int(k);
        size= k;
    }
    
    bool insertFront(int value) {
        if(isEmpty())
        {
            front =0;
            rear=0;
            arr[front]=value;
        }
        else if(isFull())
        {
            return false;
        }
        else
        {
            if (front==0)
            {
                front=size-1;
                arr[front]=value;
            }
            else
            {
                front--;
                arr[front]=value;
            }
            
        }
        
    }
    
    bool insertLast(int value) {
        if(isEmpty())
        {
            front=0;
            rear=0;
            arr[rear]=value;
            return true;
        }
        else if(isFull())
        {
            return false;
        }
        else
        {
            
            rear=(rear+1)%size;
            arr[rear]=value;
            return true;
        }
    }
    
    bool deleteFront() {
        if (isEmpty())
        {
            return false;
        }
        else if(front==rear)
        {
            front=-1;
            rear=-1;
            return true;
        }
        else 
        {
            front=(front+1)%size;
            return true;

        }
        
    }
    
    bool deleteLast() {
        if (isEmpty())
        {
            return false;
        }
        else if(front==rear)
        {
            front=-1;
            rear=-1;
            return true;
        }
        else 
        {
            if(rear==0)
            {
                rear=size-1;
            }
            else
            {
                rear=rear-1;
            }
            

        }
        
    }
    
    int getFront() {
        return arr[front];
    }
    
    int getRear() {
        return arr[rear];
    }
    
    bool isEmpty() {
        if(front ==-1&&rear==-1)
        {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(front-rear==1)
        {
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
int main()
{
    
    return 0;
}