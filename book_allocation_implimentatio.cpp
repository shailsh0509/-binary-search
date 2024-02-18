#include <bits/stdc++.h>
using namespace std;
bool isposible(int arr[], int n, int m, int curr_min)
{
    // m is students
    int student = 1;
    int pages_reading = 0;
    for (int i = 0; i < n; i++)
    {
        // if (arr[i] > curr_min)
        // {
        // }
        if (pages_reading + arr[i] > curr_min)
        {
            student++;
            pages_reading = arr[i];
            if (student > m)
            {
                return false;
            }
        }
        else
        {
            pages_reading += arr[i];
        }
    }
    if (student > m)
    {
        return false;
    }
    return true;
}
int solve()
{
    int n, student;
    cin >> n >> student;
    int arr[n];
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if (n < student)
    {
        return -1;
    }
    int s = arr[n - 1];
    int e = sum;
    int ans = INT_MAX;
    while (s <= e)
    {
        int mid = ((s + e) >> 1);
        if (isposible(arr, n, student, mid))

        {
            ans = min(ans, mid);
            e = mid - 1;
        }
        else
        {
            //  not posible to divide the x page
            s = mid + 1;
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
        cout << solve() << endl;
    }
    return 0;
}