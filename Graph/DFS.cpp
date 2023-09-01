// Q: 
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
vector<int> adj[N];
bool visited[N];
void dfs(int u)
{
    // section 1: actions just after entering node u
    visited[u] = true;
    cout << u << " ";
    for(int v: adj[u])
    {
        // section 2: actions before entering a new neighbor 
        if(visited[v]) continue; 
        dfs(v);
        // section 3: actions after exiting a neighor
    }
    // section 4: actions before exiting node u
    
}
int main()
{
    int n, m;
    cin >> n >> m;
    // taking input in adjacency list
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    
    return 0;
}