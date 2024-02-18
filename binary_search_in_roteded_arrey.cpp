#include <bits/stdc++.h>
using namespace std;
int search_rotedet_arrey(int arr[], int n, int key)
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
        else if (arr[s] <= arr[mid])
        {
            if (key >= arr[s] and key <= arr[mid])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        else
        {
            if (key >= arr[mid] and key <= arr[e])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;
    cout << search_rotedet_arrey(arr, n, key) << endl;
    return 0;
}
// 7
// 7 6 5 1 2 3 4
// 3