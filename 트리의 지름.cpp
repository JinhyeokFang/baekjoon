#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> edges[10001];
int n;
bool visited[10001] = {0,};

pair<int, int> solv(int point)
{
    int cost = 0;
    int temp = 0;
    visited[point] = true;
    for (int i=0; i<edges[point].size(); i++)
    {
        if (visited[edges[point][i].first])
            continue;
        pair<int, int> result = solv(edges[point][i].first);
        int child_cost = result.second + edges[point][i].second;
        if (child_cost > cost)
        {
            cost = child_cost;
            temp = result.first;
        }
    }
    if (cost != 0)
        return {temp, cost};
    return {point, 0};
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i=0; i<n-1; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
    pair<int, int> result1 = solv(1);
    for (int i=0; i<=n; i++)
        visited[i] = false;
    pair<int, int> result2 = solv(result1.first);
    cout << result2.second;
}