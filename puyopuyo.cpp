#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

const int h = 12, w = 6;
int map[6][12];
bool visited[6][12];
bool visitede[6][12];

void erase(int x, int y)
{
    visitede[x][y] = true;
    if (x > 0 && !visitede[x - 1][y] && map[x][y] == map[x - 1][y])
        erase(x - 1, y);
    if (x < w - 1 && !visitede[x + 1][y] && map[x][y] == map[x + 1][y])
        erase(x + 1, y);
    if (y > 0 && !visitede[x][y - 1] && map[x][y] == map[x][y - 1])
        erase(x, y - 1);
    if (y < h - 1 && !visitede[x][y + 1] && map[x][y] == map[x][y + 1])
        erase(x, y + 1);
    map[x][y] = 0;
}

int num_of_puyo(int x, int y)
{
    int count = 1;
    visited[x][y] = true;
    if (x > 0 && !visited[x - 1][y] && map[x][y] == map[x - 1][y])
        count += num_of_puyo(x - 1, y);
    if (x < w - 1 && !visited[x + 1][y] && map[x][y] == map[x + 1][y])
        count += num_of_puyo(x + 1, y);
    if (y > 0 && !visited[x][y - 1] && map[x][y] == map[x][y - 1])
        count += num_of_puyo(x, y - 1);
    if (y < h - 1 && !visited[x][y + 1] && map[x][y] == map[x][y + 1])
        count += num_of_puyo(x, y + 1);
    return count;
}

bool pang()
{
    memset(visited, 0, 6 * 12);
    memset(visitede, 0, 6 * 12);
    bool result = false;
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            if (map[x][y] != 0 && !visited[x][y] && 4 <= num_of_puyo(x, y))
            {
                erase(x, y);
                result = true;
            }
        }
    }
    return result;
}

void gravity()
{
    vector<int> v;
    for (int x = 0; x < w; x++)
    {
        for (int y = 0; y < h; y++)
        {
            if (map[x][y] != 0)
                v.push_back(map[x][y]);
        }
        for (int y = 0; y < h; y++)
        {
            if (y < v.size())
                map[x][y] = v[y];
            else
                map[x][y] = 0;            
        }
        v.clear();
    }
}

int solve()
{
    int count = 0;
    while (pang())
    {
        count++;
        gravity();
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i=11; i>=0; i--)
    {
        for (int j=0; j<6; j++)
        {
            char c;
            cin >> c;
            if (c == '.')
                map[j][i] = 0;
            if (c == 'G')
                map[j][i] = 1;
            if (c == 'R')
                map[j][i] = 2;
            if (c == 'B')
                map[j][i] = 3;
            if (c == 'P')
                map[j][i] = 4;
            if (c == 'Y')
                map[j][i] = 5;
        }
    }
    cout << solve() << '\n';
}