
// Ref = https://www.geeksforgeeks.org/dsa/hierholzers-algorithm-directed-graph/
// Ref = https://www.shafaetsplanet.com/?p=3169

// Euler circuit
    vector<int> currPath, circuit;
    currPath.pb(0);
    while(currPath.size() > 0)
    {
        int currNode = currPath.back();

        if(adj[currNode].size() > 0){
            currPath.pb(adj[currNode].back());
            adj[currNode].pop_back();
        }
        else{
            circuit.pb(currNode);
            currPath.pop_back();
        }
    }
    reverse(circuit.begin(), circuit.end());

    // Euler Circuit gives k*k+1 unique edges
    // and start and end node is same

