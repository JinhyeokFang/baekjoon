#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, pair<int, int>> edge;
int parent[10000];
int v, e;
int result = 0;

priority_queue<edge> edges;

int getRoot(int node)
{
    int& currentParent = parent[node];
    if (node == currentParent)
        return node;
    return currentParent = getRoot(currentParent);
}

bool finished()
{
    int root = getRoot(0);
    for (int i=1; i<v; i++)
    {
        if (root != getRoot(i))
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e;
    for (int i=0; i<v; i++)
        parent[i] = i;
    for (int i=0; i<e; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        edges.push({-cost, {start, end}});
    }
    do
    {
        edge topEdge = edges.top();
        int cost = -topEdge.first;
        int start = topEdge.second.first;
        int end = topEdge.second.second;
        edges.pop();
        if (getRoot(start) != getRoot(end))
        {
            parent[getRoot(start)] = end;
            result += cost;
        }
    } while (!finished());
    cout << result;
}