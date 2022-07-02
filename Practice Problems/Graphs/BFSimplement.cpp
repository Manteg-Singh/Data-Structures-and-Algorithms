#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int n,e;
    cout<<"Enter the number of vertices & Edges\n";
    cin>>n>>e;

    vector<vector<int>> GraphMatrix(n,vector<int>(n,0));
    for(int i=0;i<e;i++)
    {
        int f,s;
        cout<<"Enter the vertex & then the vertex it is connected to\n";
        cin>>f;       
        cin>>s;
        GraphMatrix[f][s]=1;
        GraphMatrix[s][f]=1;
    }

    vector<bool> visited(n,false);
    queue<int> q;
    int start=0;
    q.push(start);
    visited[start]=true;
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        for (int i = 0; i < n; i++)
        {
            if (GraphMatrix[q.front()][i]==1 && !visited[i])
            {
                q.push(i);
                visited[i]=true;
            }
            
        }
        q.pop();
        
        
    }
    
    




    return 0;
}