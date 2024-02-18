#include <bits/stdc++.h>
using namespace std;
int root(int n)
{
    int ans = -1;
    int s = 1;
    int e = n;
    //  time log(n)
    while (s <= e)
    {
        int mid = ((s + e) >> 1);
        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = root(n);
        cout << ans << endl;
    }
    return 0;
}