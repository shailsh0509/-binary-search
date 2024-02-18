#include <bits/stdc++.h>
using namespace std;
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
    buildtree(arr, mid + 1, e, tree, (2 * index) + 1);
    tree[index] = (tree[index * 2] ^ tree[(2 * index) + 1]);
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
        return (left ^ right);
    }
}
int main()
{
    int n;
    cin >> n;
    int q;
    cin >> q;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int *tree = new int[4 * n + 1];
    // void buildtree(int arr[], int s, int e, int tree[], int index)

    buildtree(arr, 0, n - 1, tree, 1);

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        // int query(int tree[], int index, int s, int e, int qs, int qe)

        cout << query(tree, 1, 0, n - 1, a - 1, b - 1) << endl;
    }
    return 0;
}