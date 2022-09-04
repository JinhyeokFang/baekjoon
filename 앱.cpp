#include <iostream>

using namespace std;

int n, m;
int memory[100][10001];
int bytes[100];
int costs[100];

int max_memory(int n, int cost)
{
    int& result = memory[n][cost];
    if (result != 0)
        return result;
    if (n == 0)
    {
        if (costs[0] <= cost)
            return result = bytes[0];
        else
            return 0;        
    }
    result = max_memory(n - 1, cost);
    if (costs[n] <= cost)
        result = max(result, bytes[n] + max_memory(n - 1, cost - costs[n]));
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> bytes[i];
    for (int i=0; i<n; i++)
        cin >> costs[i];
    for (int i=0; i<=10001; i++)
    {
        int mem = max_memory(n - 1, i);
        if (mem >= m)
        {
            cout << i;
            return 0;
        }
    }
}
