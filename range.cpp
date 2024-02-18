#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 1;
// int lazy[N] = {0};
#define ll long long int
ll lazy[4 * N + 1] = {0};

void biuld(ll arr[], ll s, ll e, ll tree[], ll index)
{
    if (s == e)
    {
        tree[index] = arr[s];
        return;
    }
    else
    {
        ll mid = (s + e) / 2;
        biuld(arr, s, mid, tree, 2 * index);
        biuld(arr, mid + 1, e, tree, 2 * index + 1);
        tree[index] = (tree[2 * index] + tree[2 * index + 1]);
    }
}
void update(ll tree[], ll ss, ll se, ll l, ll r, ll inc, ll index)
{
    // before going down resilve the value if its exit
    if (lazy[index] != 0)
    {
        tree[index] += lazy[index];
        if (ss != se)
        {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }
        lazy[index] = 0; // clear the lazy value of current index
    }
    // base case
    if (ss > r or l > se)
    {
        // not ower lap
        return;
    }
    // another case
    if (ss >= l and se <= r)
    {
        tree[index] += inc;
        if (ss != se)
        {
            lazy[2 * index] += inc;
            lazy[2 * index + 1] += inc;
        }
        return;
    }
    ll mid = (ss + se) / 2;
    update(tree, ss, mid, l, r, inc, 2 * index);
    update(tree, mid + 1, se, l, r, inc, 2 * index + 1);
    tree[index] = (tree[2 * index] + tree[2 * index + 1]);
    return;
}
ll query(ll tree[], ll ss, ll se, ll index, ll l, ll r)
{
    if (lazy[index] != 0)
    {
        tree[index] += lazy[index] * (se - ss + 1);
        if (ss != se)
        {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }
        lazy[index] = 0; // clear the lazy value of current index
    }
    if (l > se or r < ss)
    {
        return 0;
    }
    if (l <= ss and r >= se)
    {
        return tree[index];
    }
    ll mid = (ss + se) / 2;
    ll left = query(tree, ss, mid, 2 * index, l, r);
    ll right = query(tree, mid + 1, se, 2 * index + 1, l, r);

    return left + right;
}
int main()
{
    ll n, q;
    cin >> n >> q;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll tree[4 * n + 1];
    biuld(arr, 0, n - 1, tree, 1);
    // // "1 a b u" or "2 k".
    // for(int i=1;i<=20;i++)
    // {
    //     cout<<i<<" "<<tree[i]<<endl;
    // }
    while (q--)
    {
        int m;
        cin >> m;
        if (m == 1)
        {
            ll b, c, u;
            cin >> b >> c >> u;
            // void update(int tree[], int ss, int se, int l, int r, int inc, int index)

            update(tree, 0, n - 1, b - 1, c - 1, u, 1);
        }
        else
        {
            ll b;
            cin >> b;
            //  query(int tree[], int ss, int se, int index, int l, int r)
            cout << query(tree, 0, n - 1, 1, b - 1, b - 1) << endl;
        }
    }
    return 0;
}