#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, e, weight;
    cout << "Enter the number of vertices & Edges\n";
    cin >> n >> e;
    vector<bool> visited(n, false);
    bool *visit = new bool(n);

    for (int i = 0; i < n; i++)
    {
        visit[i] = false;
    }

    vector<vector<int>> GraphMatrix(n, vector<int>(n, 0));
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cout << "Enter the vertex & then the vertex it is connected to\n";
        cin >> f >> s;
        cout << "Enter their weight\n";
        cin >> weight;
        GraphMatrix[f][s] = 1;
        GraphMatrix[s][f] = 1;
    }

    return 0;
}