#include<bits/stdc++.h>
using namespace std;

//heapify == convert an array to heap (max or min)
//following max heapify
void heapify(int arr[], int n, int i)
{
    int largest = i; // following max heapify
    int leftchild = 2 * i + 1; // following zero based indexing
    int rightchild = 2 * i + 2;

    if (leftchild < n && arr[largest] < arr[leftchild]) // while following 1 based indexing then (leftchild <= n)
        largest = leftchild;

    if (rightchild < n && arr[largest] < arr[rightchild]) // while following 1 based indexing then (rightchild <= n)
        largest = rightchild;
    
    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }

}


int main()
{
    int n;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    // In Complete Binary Tree leaf node lies on (n/2) + 1 --> n {1 based indexing}
    // In Complete Binary Tree leaf node lies on (n/2)  --> n {0 based indexing}
    // we don't need to start frocessing from leaf nodes;

    int start = (n /2) - 1; // following zero based indexing
    for(int i = start; i >= 0; i--)
        heapify(arr, n, i);
    
    //printing
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}