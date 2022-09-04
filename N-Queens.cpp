#include <iostream>

using namespace std;

int check(int arr[], int n, int m)
{
    for (int i=0; i<n; i++)
    {
        if (m == arr[i] || i - n == arr[i] - m || i + arr[i] == m + n)
            return 0;
    }
    return 1;
}

int solv(int arr[], int n, int c)
{
    int sum = 0;
    if (c == n)
        return 1;
    for (int i=0; i<n; i++)
    {
        if (check(arr, c, i))
        {
            arr[c] = i;
            sum += solv(arr, n, c + 1);
        }
    }
    return sum;
}

int main()
{
    int arr[15] = { 0, };
    int n;
    cin >> n;
    cout << solv(arr, n, 0);
}