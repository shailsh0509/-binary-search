#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;

    if (k >= n)
    {
        if (k % n == 0)
        {
            cout << (k / n) << endl;
        }
        else
        {
            cout << (k / n) + 1 << endl;
        }
    }
    else
    {
        if (n % k == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << (n / k) + 1 << endl;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}