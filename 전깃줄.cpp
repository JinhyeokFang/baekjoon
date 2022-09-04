#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int memory[100];
int n;
vector<pair<int, int>> wires;

int lcs(int index)
{
    if (index == -1)
    {
        int result = 0;
        for (int i=0; i<n; i++)
            result = max(result, lcs(i));
        return result;
    }
    int& result = memory[index];
    if (result != 0)
        return result;
    if (index == n - 1)
        return result = 1;
    result = 1;
    for (int i=index + 1; i<n; i++)
    {
        if (wires[index].second < wires[i].second)
            result = max(result, lcs(i) + 1);
    }
    return result;
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first <= b.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int start, end;
        cin >> start >> end;
        wires.push_back({start, end});
    }
    sort(wires.begin(), wires.end(), compare);
    cout << n - lcs(-1);
}