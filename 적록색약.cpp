#include <iostream>
#include <memory.h>

using namespace std;

int n;
bool visited[100][100];
int map[100][100];

void visit(int x, int y)
{
    visited[x][y] = true;
    if (x > 0 && !visited[x - 1][y] && map[x][y] == map[x - 1][y])
        visit(x - 1,y);
    if (x < n - 1 && !visited[x + 1][y] && map[x][y] == map[x + 1][y])
        visit(x + 1,y);
    if (y > 0 && !visited[x][y - 1] && map[x][y] == map[x][y - 1])
        visit(x,y - 1);
    if (y < n - 1 && !visited[x][y + 1] && map[x][y] == map[x][y + 1])
        visit(x,y + 1);
}

int count()
{
    int sum = 0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (!visited[j][i])
            {
                visit(j, i);
                sum++;
            }
        }
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            char c;
            cin >> c;
            map[j][i] = c == 'R' ? 1 : c == 'G' ? 2 : 3;
        }
    }
    cout << count() << ' ';
    memset(visited, 0, 100*100);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (map[j][i] == 1)
                map[j][i] = 2;
        }
    }
    cout << count();
}