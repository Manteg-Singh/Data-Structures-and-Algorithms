#include <iostream>
#include <vector>
using namespace std;

void DepthFirstSearch(int start, vector<vector<int>> matrix, int edges, int n, bool * visit)
{
    visit[start] = true;
    cout << start << " ";
    for (int i = 0; i < n; i++)
    {
        if (matrix[start][i] == 1 && !visit[i])
        {
            DepthFirstSearch(i, matrix, edges, n, visit);
        }
    }
    return;
}

int main()
{
    int n, e;
    cout << "Enter the number of vertices & Edges\n";
    cin >> n >> e;
    vector<bool> visited(n, false);
    bool * visit= new bool(n);
    for (int i = 0; i < n; i++)
    {
        visit[i]=false;
    }
    
    vector<vector<int>> GraphMatrix(n, vector<int>(n, 0));
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cout << "Enter the vertex & then the vertex it is connected to\n";
        cin >> f;
        cin >> s;
        GraphMatrix[f][s] = 1;
        GraphMatrix[s][f] = 1;
    }

    DepthFirstSearch(0, GraphMatrix, e, n, visit);

    return 0;
}