#include <bits/stdc++.h>
using namespace std;

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
    bool prasent = binary_search(arr, arr + n, key);
    if (prasent)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    auto first_index = lower_bound(arr, arr + n, key);
    cout << first_index - arr << endl;
    auto last_index = upper_bound(arr, arr + n, key);
    cout << last_index - arr << endl;
    cout << "fraqunce"
         << " " << last_index - first_index << endl;
    return 0;
}
// 8
// 1 2 3 3 3 3 7 8
// 3