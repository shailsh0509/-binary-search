#include <bits/stdc++.h>
using namespace std;

void update(int i, int inc, int n, int bit[])
{
    while (i <= n)
    {

        bit[i] += inc;
        i += (i & (-i));
    }
}
int query(int i, int bit[])
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        // memset(bit, sizeof(bit), 0);
        int bit[n + 1] = {0};
        for (int i = 1; i <= q; i++)
        {
            int a, b, val;
            cin >> a >> b >> val;
            a++, b++;
            update(a, val, n, bit);
            update(b + 1, -val, n, bit);
        }

        cin >> q;
        while (q--)
        {
            int index;
            cin >> index;
            cout << query(index + 1, bit) << endl;
        }
    }

    return 0;
}