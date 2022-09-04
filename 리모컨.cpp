#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int n, m;
bool is_broken[10];
bool visited[5000001];

bool able_to_move(int n)
{
    if (n == 0 && is_broken[0])
        return false;
    for (int i = n; i > 0; i /= 10)
    {
        if (is_broken[i % 10])
            return false;
    }
    return true;
}

int get_nearest_number(int n)
{
    queue<int> q;
    q.push(n);
    visited[n] = true;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        if (able_to_move(top))
            return top;
        if (top > 0 && !visited[top - 1])
        {
            visited[top - 1] = true;
            q.push(top - 1);
        }
        if (!visited[top + 1])
        {
            visited[top + 1] = true;
            q.push(top + 1);
        }
    }
    return 1000000;
}

int count_move(int n)
{
    int nearest_number = get_nearest_number(n);
    int count_nearest_number = nearest_number >= 10 ? log10(nearest_number) + 1 : 1;
    return min(abs(n - 100), abs(n - nearest_number) + count_nearest_number);
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        int tmp;
        cin >> tmp;
        is_broken[tmp] = true;
    }
    cout << count_move(n);
}
