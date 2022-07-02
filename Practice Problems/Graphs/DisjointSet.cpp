#include <bits/stdc++.h>

using namespace std;

int findPar(int node, vector<pair<int, int>> &Node)
{
    if(Node[node].first==node) return node;

    Node[node].first=findPar(Node[node].first,Node);
    return Node[node].first;

}
void unionOp(int node1, int node2, vector<pair<int, int>> &Node)
{
    node1=findPar(node1,Node);
    node2=findPar(node2,Node);
    if(Node[node1].second>Node[node2].second)
    {
        Node[node2].first=node1;
    }
    else if(Node[node1].second<Node[node2].second)
    {
Node[node1].first=node2;
    }
    else
    {
        Node[node2].first=node1;
        Node[node1].second++;
    }
    
}

int main()
{   
    int n, e;
    cin >> n >> e;
    // vector<pair<int, int>> adj[n];
    // for (int i = 0; i < e; i++)
    // {
    //     int u, v, wt;
    //     cin >> u >> v >> wt;
    //     adj[u].push_back({v, wt});
    //     adj[v].push_back({u, wt});
    // }
    vector<pair<int, int>> Node(n, {-1, 0}); //{Parent of Node,Rank of Node}
    for (int i = 0; i < Node.size(); i++)
    {
        Node[i].first=i;
    }
    
    cout << "Enter no of Union Operations u wanna perform" << endl;
    int x,n1, n2;
    
    for (int i = 0; i < x; i++)
    {
        cout << "Enter node 1 and Node 2\n";

        cin >> n1 >> n2;
        unionOp(n1, n2, Node);
    }

    cout << "Enter 2 Nodes whose parents u wanna chk equal or not\n";
    cin >> n1 >> n2;

    if (findPar(n1, Node) == findPar(n2, Node))
        cout << "Ek hi baap dono ka\n";
    else
        cout << "Alag baap h :(\n";

    return 0;
}