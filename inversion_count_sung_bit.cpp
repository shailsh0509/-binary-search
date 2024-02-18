#include <bits/stdc++.h>
using namespace std;
int arr[100000];
int bit[10000] = {0};// 
void update(int i, int inc, int n)
{
    while (i <= n)
    {
        bit[i] += inc;
        i += (i & (-i));
    }
}
int query(int i)
{
    int ans = 0;
    while (i > 0)
    {
        ans += bit[i];

        i -= (i & (-i));
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = n; i > 0; i--)
    {
        ans += query(arr[i] - 1);
        update(arr[i], 1, n);
    }
    cout << ans << endl;
    return 0;
}