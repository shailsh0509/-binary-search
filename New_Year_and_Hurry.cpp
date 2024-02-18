#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    int m = 240 - k;
    int ans = 0;
    int i = 1;
    int sum = 0;

    while (i * 5 + sum <= m)
    {
        sum += i * 5;
        i = i + 1;
        ans += 1;
        if (ans == n)
        {
            cout << ans << endl;
            return;
        }
    }
    cout << ans << endl;
}
int main()
{
    solve();
    return 0;
}