// Q: Find the shortest distance for all the pair of nodes
//(APSA)-> All Pair Shortest Algorithm
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
const int INF = 100000;
int adj[N][N];
int n, m;
void initialize()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i != j) adj[i][j] = INF;
}
void floyd_warshall()
{
    // take a node(k) and check can we go from
    // node i to node j through node k. (i->k->j)
    // If we can, then compare the cost of i->j with cost of i->k->j
    // If there is no such path (i->k->j) then the cost remain unchanged
    // Because the cost of node k initially Infinite
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
}
void print()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(adj[i][j] == INT_MAX) cout << "X ";
            else cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    cin >> n >> m;
    // initialize the matrix by INF
    initialize();
    while(m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }
    floyd_warshall();
    cout <<"After Floyd Warshall: \n";
    print();    
    return 0;
}