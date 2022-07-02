#include <iostream>
#include<deque>
using namespace std;
class FrontMiddleBackQueue {
    deque<int> f,r;
    void sizeRgreater()
    {
       
            f.push_back(r.front());
            r.pop_front();
        
    }
    void sizeFgreater()
    {
        
            r.push_front(f.back());
            f.pop_back();
        
    }
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        
        f.push_front(val);
        sizeFgreater();
        
        return;

    }
    
    void pushMiddle(int val) {
        if(f.size()==r.size())
        { r.push_front(val);
        sizeRgreater();
         return;
        }
        else
        {
            f.push_back(val);
            return;
            
        }
     
    }
    
    void pushBack(int val) {
        r.push_back(val);
        sizeRgreater();
                 return;

     
    }
    
    int popFront() {
        if(f.empty()&&r.empty())
            return -1;
        else if (f.empty())
        {
            int temp= r.front();
            r.pop_front();
            return temp;
        }
        else
        {
            int temp = f.front();
            f.pop_front();
             sizeRgreater();
            return temp;
        }
    }
    
    int popMiddle() {
        if(f.empty()&&r.empty())
            return -1;
        else
        {
            if(f.size()==r.size())
            {
                int temp = f.back();
                f.pop_back();
                 //sizeRgreater();
                return temp;
                
            }
            else
            {
                 int temp = r.front();
                r.pop_front();
                // sizeFgreater();
                return temp;
            }
        }
    }
    
    int popBack() {
        if(f.empty()&&r.empty())
            return -1;
        int temp=r.back();
        r.pop_back();
        sizeFgreater();
        return temp;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
int main()
{
    FrontMiddleBackQueue s1;
    
    s1.pushFront(1);
    // s1.pushFront(2);
    // s1.pushFront(3);
    // s1.pushFront(4);
   cout<<s1.popMiddle()<<endl;
   cout<<s1.popMiddle()<<endl;
   cout<<s1.popBack()<<endl;
    cout<<s1.popBack()<<endl;
    return 0;
}