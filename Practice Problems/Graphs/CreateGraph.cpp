#include <iostream>


using namespace std;

class graph{
    int n;
    vector<pair<int,int>> adj[n];
    public:
    graph(int noOfNodes){
        n=noOfNodes;
        
    }
    
    addEdge(int n1, int n2, int wt, vector<int> adj[]){
        adj[n1].push_back({n2,wt});
        adj[n2].push_back({n1,wt});

    }
    
} 
int main()
{
    

    
    return 0;
}