#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
long long arr[N];
class Node
{
public:
    long long prifix_sum;
    long long sum;
};
Node tree[4 * N + 1];
void build(long long s, long long e, long long index)
{
    if (s == e)
    {
        tree[index] = (Node{arr[s], arr[s]});
        return;
    }
    long long mid = (s + e) / 2;
    build(s, mid, 2 * index);
    build(mid + 1, e, 2 * index + 1);
    Node left = tree[2 * index];
    Node right = tree[2 * index + 1];
    tree[index].prifix_sum = max(left.prifix_sum, left.sum + right.prifix_sum);
    tree[index].sum = left.sum + right.sum;
}
Node query(int s, int e, int l, int r, int index)
{
    // cout << -1 << endl;

    if (s >= l and e <= r)
    {
        return tree[index];
    }
    if (l > e || r < s)
    {
        return (Node{0, 0});
    }
    int mid = (s + e) / 2;
    Node left = query(s, mid, l, r, 2 * index);
    Node right = query(mid + 1, e, l, r, 2 * index + 1);
    Node ans;
    ans.prifix_sum = max(left.prifix_sum, left.sum + right.prifix_sum);
    ans.sum = left.sum + right.sum;
    return ans;
}
void update(int s, int e, int i, int val, int index)
{
    // cout << -1 << endl;
    if (i < s or i > e)
    {
        return;
    }
    else if (s == e)
    {
        tree[index] = (Node{val, val});
        return;
    }
    long long mid = (s + e) / 2;
    update(s, mid, i, val, 2 * index);
    update(mid + 1, e, i, val, 2 * index + 1);

    Node left = tree[2 * index];
    Node right = tree[2 * index + 1];
    tree[index].prifix_sum = max(left.prifix_sum, left.sum + right.prifix_sum);
    tree[index].sum = left.sum + right.sum;
}
int main()
{
    long long n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(0, n - 1, 1);
    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            update(0, n - 1, b - 1, c, 1);
        }
        else
        {

            Node p = query(0, n - 1, b - 1, c - 1, 1);

            if (p.prifix_sum >= 0)
            {
                cout << p.prifix_sum << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}
// 8 1
// 1 2 -1 3 1 -5 1 4
// 2 2 6