// Q: find the number of component in a graph by using disjoint set union
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int parent[N];
int Size[N];
void make(int v)
{
    // every node initially parent of itself and size of 1
    parent[v] = v;
    Size[v] = 1;
}
int find(int v)
{
    if (parent[v] == v)
        return v;
    // path compression   -> when we call find function it
    // returns the parent/root of the whole set it belongs. so 
    // we can set the parent/root of the set for all the nodes
    // of the path it's going through.
    return parent[v] = find(parent[v]);
}
void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        // union by size
        // always connecting smaller set to the bigger set
        if (Size[a] < Size[b])
            swap(a, b);
        parent[b] = a;
        // after connecting set b to a, the size of set 'a' is increased by a+b 
        Size[a] += Size[b];
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        make(i);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        // connection two components/ sets
        Union(u, v);
    }
    int connected_comp = 0;
    for (int i = 1; i <= n; i++)
        if(find(i) == i) connected_comp++;
    cout << connected_comp << "\n";
    return 0;
}
// source : https://www.youtube.com/watch?v=zEAmQqOpfzM