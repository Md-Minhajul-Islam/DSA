/*
    Q: You will be given an adjacency matrix for a directed graph
    (index starting from 1) as input.
    Now, convert it to an adjacency list and print it.
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+4;
int adjMatrix[N][N];
vector<int> adjList[N];
int main()
{
    int n;
    cin >> n;
    // taking input in adjacency Matrix
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> adjMatrix[i][j];
    // Converting adjacency matrix to adjacency list
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(adjMatrix[i][j])
                adjList[i].push_back(j);
    for(int i = 1; i <= n; i++)
    {
        cout << "List " << i << " : ";
        for(int j: adjList[i])
            cout << j << " ";
        cout << endl;
    }
    return 0;
}