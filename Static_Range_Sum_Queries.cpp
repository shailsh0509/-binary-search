#include <bits/stdc++.h>
using namespace std;
// const int N = 2 * 1e5 + 1;
void biuld_tree(long long tree[], long long index, long long arr[], long long s, long long e)
{
    if (s == e)
    {
        tree[index] = arr[s];
        return;
    }
    else
    {
        long long mid = (s + e) / 2;
        biuld_tree(tree, index * 2, arr, s, mid);
        biuld_tree(tree, 1 + index * 2, arr, mid + 1, e);
        tree[index] = tree[index * 2] + tree[2 * index + 1];
    }
}
long long query(long long tree[], long long index, long long s, long long e, long long qs, long long qe)
{
    if (s >= qs and e <= qe)
    {
        return tree[index];
    }
    else if (s > qe || e < qs)
    {
        return 0;
    }
    else
    {
        long long mid = (s + e) / 2;
        long long left = query(tree, index * 2, s, mid, qs, qe);
        long long right = query(tree, 1 + index * 2, mid + 1, e, qs, qe);
        return left + right;
    }
}
int main()
{
    long long n, q;
    cin >> n >> q;
    long long arr[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long tree[4 * n + 1];
    biuld_tree(tree, 1, arr, 0, n - 1);
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << query(tree, 1, 0, n - 1, a - 1, b - 1) << endl;
    }
    return 0;
}