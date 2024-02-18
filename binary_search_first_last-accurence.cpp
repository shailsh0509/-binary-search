#include <bits/stdc++.h>
using namespace std;
int first_accurencebinary_search(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = ((s + e) >> 1);
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] > key)
        {
           e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}
int last_accurencebinary_search(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = ((s + e) >> 1);
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
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
    cout << first_accurencebinary_search(arr, n, key) << " " << last_accurencebinary_search(arr, n, key) << endl;
    return 0;
}
// 8
// 1 2 3 3 3 3 7 8
// 3