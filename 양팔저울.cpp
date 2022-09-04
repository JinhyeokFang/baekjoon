#include <iostream>

using namespace std;

bool visited[30][100000];
bool memory[30][100000];
int weights[30];

bool solve(int n, int weight)
{
    if (weight < 0)
        weight = abs(weight);
    bool& result = memory[n][weight];
    bool& is_visited = visited[n][weight];
    if (is_visited)
        return result;
    is_visited = true;
    if (weight == 0)
        return true;
    if (n == 0)
        return result = weight == weights[0];
    return (
        solve(n - 1, weight - weights[n]) ||
        solve(n - 1, weight + weights[n]) ||
        solve(n - 1, weight)
    );
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> weights[i];
    int k;
    cin >> k;
    for (int i=0; i<k; i++)
    {
        int w;
        cin >> w;
        if (solve(n - 1, w))
            cout << "Y ";
        else
            cout << "N ";        
    }
}
