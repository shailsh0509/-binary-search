#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 1;
long long arr[N];
long long bit[N + 1];
void update(int i, int inc, int n)
{
    while (i <= n)
    {
        bit[i] += inc;
        i += (i & (-i));
    }
}
long long query(int i)
{
    long long ans = 0;
    while (i > 0)
    {
        ans += bit[i];

        i -= (i & (-i));
    }
    return ans;
}
int main()
{
    long long n, q;
    cin >> n >> q;
    long long arr[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        update(i, arr[i], n);
    }
    while (q--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            int inc = c - arr[b];
            arr[b] = c;
            update(b, inc, n);
        }
        else
        {
            cout << query(c) - query(b - 1) << endl;
        }
    }
    return 0;
}