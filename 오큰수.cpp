#include <iostream>
#include <stack>

using namespace std;

int arr[1000000];
int n;

void solve()
{
    stack<int> s;
    for (int i=n-1; i>=0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();
        int tmp = arr[i];
        if (s.empty())
            arr[i] = -1;
        else
            arr[i] = s.top();
        s.push(tmp);
    }
    for (int i=0; i<n; i++)
        cout << arr[i] << ' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> arr[i];
    solve();
}