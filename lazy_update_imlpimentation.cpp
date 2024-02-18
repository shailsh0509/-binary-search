#include <bits/stdc++.h>
using namespace std;
int lazy[1000] = {0};
void biuld(int arr[], int s, int e, int tree[], int index)
{
    if (s == e)
    {
        tree[index] = arr[s];
        return;
    }
    else
    {
        int mid = (s + e) / 2;
        biuld(arr, s, mid, tree, 2 * index);
        biuld(arr, mid + 1, e, tree, 2 * index + 1);
        tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    }
}
void update(int tree[], int ss, int se, int l, int r, int inc, int index)
{
    // before going down resilve the value if its exit
    if (lazy[index] != 0)
    {
        tree[index] += lazy[index];
        if (ss != se)
        {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] + lazy[index];
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
    int mid = (ss + se) / 2;
    update(tree, ss, mid, l, r, inc, 2 * index);
    update(tree, mid + 1, se, l, r, inc, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int tree[4 * n + 1];
    biuld(arr, 0, n - 1, tree, 1);
    return 0;
}