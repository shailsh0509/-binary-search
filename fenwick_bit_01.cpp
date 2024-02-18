#include <bits/stdc++.h>
using namespace std;
int arr[10000];
int bit[10000] = {0};
void update(int i, int inc, int n)
{
    while (i <= n)
    {
        bit[i] += inc;
        i += (i & (-i));
    }
}
// sum till the ith index time(log(n))
int query(int i)
{
    int ans = 0;
    while (i >= 0)
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
    // build the bit
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        update(i, arr[i], n);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(r) - query(l - 1) << endl;
    }
    return 0;
}