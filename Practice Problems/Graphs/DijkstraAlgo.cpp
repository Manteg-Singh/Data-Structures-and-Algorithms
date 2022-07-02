#include <iostream>
#include <vector>
using namespace std;

int min_vertex(vector<int> & distance,vector<bool> & visited)
{
    int min_mum = INT_MAX;
    int minVertex = -1;
    for (int i = 0; i < distance.size(); i++)
    {
        if (!visited[i]&&distance[i]<min_mum)
        {
            min_mum=distance[i];
            minVertex=i;
        }
        
    }
    return minVertex;
    
}

void Dijkstra(vector<vector<int>> &Cost_Matrix, int n)
{
    int u = 0;
    int *parent = new int(n);
    vector<int> distance(n, INT_MAX);
    distance[u] = 0;
    vector<bool> visited(n, false);
    visited[u] = true;
    parent[u]=-1;
    
    for (int i = 0; i < n - 1; i++)
    {
  
        for (int j = 0; j < n; j++)
        {
            if (Cost_Matrix[u][j] > 0 && !visited[j] && (distance[u] + Cost_Matrix[u][j] < distance[j]))
            {
                distance[j] = distance[u] + Cost_Matrix[u][j];
                parent[j] = u;
            }
        }
        u = min_vertex(distance,visited);
        visited[u]=true;
    }

    for (int i = 1; i < n; i++)
    {
        cout << "Distance of vertex " << i << " from source node 0 is " << distance[i] << endl;
        cout << parent[i] << "-->" << i << " and their weight is " << Cost_Matrix[parent[i]][i] << endl;
    }
}
int main()
{
    int vertices, e;
    cout << "Enter No of Vertices\n";
    cin >> vertices;
    cout << "Enter no of edges\n";
    cin >> e;
    // int **GraphMatrix_Cost = new int *[vertices];
    // for (int i = 0; i < vertices; i++)
    // {
    //     GraphMatrix_Cost[i] = new int[vertices];
    // }
    // for (int i = 0; i < e; i++)
    // {
    //     int f, s,weight;
    //     cout << "Enter the vertex & then the vertex it is connected to\n";
    //     cin >> f;
    //     cin >> s;
    //     cout<<"Enter their weight\n";
    //     cin>>weight;
    //     GraphMatrix_Cost[f][s] = weight;
    //     GraphMatrix_Cost[s][f] = weight;
    // }
    vector<vector<int>> GraphMatrix_Cost = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                                    {4, 0, 8, 0, 0, 0, 0, 11, 0},
                                    {0, 8, 0, 7, 0, 4, 0, 0, 2},
                                    {0, 0, 7, 0, 9, 14, 0, 0, 0},
                                    {0, 0, 0, 9, 0, 10, 0, 0, 0},
                                    {0, 0, 4, 14, 10, 0, 2, 0, 0},
                                    {0, 0, 0, 0, 0, 2, 0, 1, 6},
                                    {8, 11, 0, 0, 0, 0, 1, 0, 7},
                                    {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    Dijkstra(GraphMatrix_Cost, vertices);

    return 0;
}