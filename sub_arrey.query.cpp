#include <bits/stdc++.h>
using namespace std;
#define MAX 200000
const int min1 = INT_MIN;
class Node
{
public:
    long long prifix_sum;
    long long suffix_sum;
    long long sum;
    long long maxsum;
};
long long arr[MAX + 1];
Node tree[4 * MAX + 1];
void make_segment_tree(long long idx, long long ss, long long se)
{
    if (ss == se)
    {
        tree[idx] = (Node{arr[ss], arr[ss], arr[ss], arr[ss]});
    }
    else
    {
        long long mid = (ss + se) / 2;
        make_segment_tree(2 * idx, ss, mid);
        make_segment_tree(2 * idx + 1, mid + 1, se);
        Node left = tree[2 * idx];
        Node right = tree[2 * idx + 1];
        tree[idx].prifix_sum = max(left.prifix_sum, left.sum + right.prifix_sum);
        tree[idx].suffix_sum = max(right.suffix_sum, right.sum + left.suffix_sum);
        tree[idx].sum = left.sum + right.sum;
        tree[idx].maxsum = max(left.suffix_sum + right.prifix_sum, max(left.maxsum, right.maxsum));
    }
}
Node query(long long idx, long long ss, long long se, long long l, long long r)
{
    if (ss >= l and se <= r)
    {
        return tree[idx];
    }
    else if (se < l or ss > r)
    {
        return (Node{min1, min1, min1, min1});
    }

    long long mid = (ss + se) / 2;
    Node left = query(2 * idx, ss, mid, l, r);
    Node right = query(2 * idx + 1, mid + 1, se, l, r);
    Node ans;
    ans.prifix_sum = max(left.prifix_sum, left.sum + right.prifix_sum);
    ans.suffix_sum = max(right.suffix_sum, right.sum + left.suffix_sum);
    ans.sum = left.sum + right.sum;
    ans.maxsum = max(left.suffix_sum + right.prifix_sum, max(left.maxsum, right.maxsum));
    return ans;
}
void update(long long ss, long long se, long long idx, long long i, long long val)
{
    if (i < ss or i > se)
    {
        return;
    }
    else if (ss == se)
    {
        tree[idx] = (Node{val, val, val, val});
        return;
    }
    long long mid = (ss + se) / 2;
    update(ss, mid, 2 * idx, i, val);
    update(mid + 1, se, 2 * idx + 1, i, val);
    Node left = tree[2 * idx];
    Node right = tree[2 * idx + 1];
    tree[idx].prifix_sum = max(left.prifix_sum, left.sum + right.prifix_sum);
    tree[idx].suffix_sum = max(right.suffix_sum, right.sum + left.suffix_sum);
    tree[idx].sum = left.sum + right.sum;
    tree[idx].maxsum = max(left.suffix_sum + right.prifix_sum, max(left.maxsum, right.maxsum));
}
int main()
{
    long long n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    make_segment_tree(1, 0, n - 1);
    // for (int i = 1; i <= 10; i++)
    // {
    //     cout << i << "  " << (tree[i].sum) << endl;
    // }

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        update(0, n - 1, 1, a - 1, b);
        // cout << query(1, 0, n - 1, 0, n - 1).maxsum << endl;
        if (query(1, 0, n - 1, 0, n - 1).maxsum >= 0)
        {
            cout << query(1, 0, n - 1, 0, n - 1).maxsum << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}
// 5
// -1 -1 3 -8 10
// 2
// 1 2
// 1 3