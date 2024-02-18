#include <bits/stdc++.h>
using namespace std;
int arr[100000];
int bit[100000] = {0};
// max value qoeery;
void update(int i, int val, int n)
{
    while (i <= n)
    {
        bit[i] = max(bit[i], val);
        i += (i & (-i));
    }
}
int query(int i)
{
    int ans = INT_MIN;
    while (i > 0)
    {
        ans = max(ans, bit[i]);
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
        update(i, arr[i], n);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int i;
        cin >> i;
        if (i == 1)
        {
            int a;
            cin >> a;
            cout << query(a) << endl;
        }
        else
        {
            int a, b;
            cin >> a >> b;
            // a is index abd b is value
            update(a, b, n);
        }
    }
    return 0;
}