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
    tree[index] = max(tree[index * 2] + tree[2 * index + 1], max(tree[index * 2], tree[2 * index + 1]));
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
        return 0;
    }
    else
    {
        int mid = (s + e) / 2;
        int left = query(tree, 2 * index, s, mid, qs, qe);
        int right = query(tree, 2 * index + 1, mid + 1, e, qs, qe);
        return max(max(left, right), left + right);
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
        tree[index] = max(max(tree[index * 2], tree[(2 * index) + 1]), tree[index * 2] + tree[(2 * index) + 1]);
        return;
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int *segment_tree = new int[4 * n + 1];
    buildtree(arr, 0, n - 1, segment_tree, 1);
    // query
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        update(segment_tree, 1, 0, n - 1, a - 1, b);
        cout << segment_tree[1] << endl;
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