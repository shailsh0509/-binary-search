#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
void buildtree(int arr[], int s, int e, int tree[], int index)
{
    if (s == e)
    {
        tree[index] = arr[s];
        return;
    }
    //  recrsive case
    int mid = ((s + e) / 2);
    buildtree(arr, s, mid, tree, 2 * index);
    buildtree(arr, mid + 1, e, tree, 2 * index + 1);
    tree[index] = min(tree[index * 2], tree[2 * index + 1]);
    return;
}
int query(int tree[], int index, int s, int e, int qs, int qe)
{
    if (s >= qs and e <= qe)
    {
        return tree[index];
    }
    if (qe < s || qs > e)
    {
        return INT_MAX;
    }
    else
    {
        int mid = (s + e) / 2;
        int left = query(tree, 2 * index, s, mid, qs, qe);
        int right = query(tree, 2 * index + 1, mid + 1, e, qs, qe);
        return min(left, right);
    }
}
void update(int tree[], int index, int ss, int se, int i, int val)
{
    //  case where the i is out of bounds
    if (i > se || i < ss)
    {
        return;
    }
    else if (ss == se) // leaf node
    {
        tree[index] = val;
        return;
    }
    else
    {
        int mid = (ss + se) / 2;
        update(tree, 2 * index, ss, mid, i, val);         // left
        update(tree, 2 * index + 1, mid + 1, se, i, val); // right
        tree[index] = min(tree[index * 2], tree[(2 * index) + 1]);
        return;
    }
}
void range_update(int tree[], int index, int s, int e, int l, int r, int val)
{
    if (r < e || l > e)
    {
        return;
    }
    if (s == e)
    {
        tree[index] = val;
    }
    else
    {
        int mid = (s + e) / 2;
        range_update(tree, index * 2, s, mid, l, r, val);
        range_update(tree, index * 2 + 1, mid + 1, e, l, r, val);
        tree[index] = min(tree[2 * index], tree[2 * index]);
    }
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
    int *segment_tree = new int[4 * n + 1];
    buildtree(arr, 0, n - 1, segment_tree, 1);
    // for (int i = 1; i <= 13; i++)
    // {
    //     cout << i << " " << segment_tree[i] << endl;
    // }
    int q;
    cin >> q;
    while (q--)
    {
        int qs, qe;
        cin >> qs >> qe;
        int ans = query(segment_tree, 1, 0, n - 1, qs, qe);
        cout << ans << endl;
    }
    update(segment_tree, 1, 0, n - 1, 3, 15);
    update(segment_tree, 1, 0, n - 1, 1, -15);
    cout << "update" << endl;

    cin >> q;
    while (q--)
    {
        int qs, qe;
        cin >> qs >> qe;
        int ans = query(segment_tree, 1, 0, n - 1, qs, qe);
        cout << ans << endl;
    }
    cout << "update_range" << endl;
    int l, r;
    cin >> l >> r;
    int val;
    cin >> val;
    range_update(segment_tree, 1, 0, n - 1, l, r, val);
    cin >> q;
    while (q--)
    {
        int qs, qe;
        cin >> qs >> qe;
        int ans = query(segment_tree, 1, 0, n - 1, qs, qe);
        cout << ans << endl;
    }
}
// 6
// 1 3 2  -5 6 4
// 4
// 0 2
// 2 5
// 3 5
// 4 5
// 4
// 0 2
// 2 5
// 3 5
// 4 5
// 1 5 100
// 4
// 0 2
// 2 5
// 3 5
// 4 5