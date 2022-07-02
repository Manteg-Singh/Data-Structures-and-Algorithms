// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/
#include<algorithm>
#include<vector>
/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
  vector<int> arr;
  while(s.size()!=0)
  {
      arr.push_back(s.top());
      s.pop();
  }
 for (int i = 0; i < arr.size()-1; i++)
    {
        for (int j = i+1; j < arr.size(); j++)
        {
            if (arr[j]<arr[i])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }       
    }
  for(int i=0; i<arr.size();i++)
  {
      s.push(arr[i]);
  }
  
}