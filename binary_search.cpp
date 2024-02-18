#include <bits/stdc++.h>
using namespace std;
int binary_search(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = ((s + e) >> 1);
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            mid = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}
int main()
{
    // cout<<(10>>1);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "enatar the search elemeny" << endl;
    int key;
    cin >> key;
    int p = binary_search(arr, n, key);
    if (p == -1)
    {
        cout << "NOt found" << endl;
    }
    else
    {
        cout << p << endl;
    }
    return 0;
}