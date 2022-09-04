#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int r, c;
bool map[1500][1500];
bool visited[1500][1500];
queue <pair<int, int>> memorized_q;

int start_x = -1, start_y = -1, end_x = -1, end_y = -1;

bool is_connected()
{
    queue<pair<int, int>> q = memorized_q;
    queue<pair<int, int>> m_q;
    if (q.empty())
        q.push({start_x, start_y});
    visited[start_x][start_y] = true;
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        int x = top.first, y = top.second;
        q.pop();
        if (x == end_x && y == end_y)
            return true;
        if (x > 0 && !map[x - 1][y] && !visited[x - 1][y])
        {
            visited[x - 1][y] = true;
            q.push({x - 1, y});
        }
        if (x < c - 1 && !map[x + 1][y] && !visited[x + 1][y])
        {
            visited[x + 1][y] = true;
            q.push({x + 1, y});
        }
        if (y > 0 && !map[x][y - 1] && !visited[x][y - 1])
        {
            visited[x][y - 1] = true;
            q.push({x, y - 1});
        }
        if (y < r - 1 && !map[x][y + 1] && !visited[x][y + 1])
        {
            visited[x][y + 1] = true;
            q.push({x, y + 1});
        }
        if (
            x > 0 && map[x - 1][y] ||
            x < c - 1 && map[x + 1][y] ||
            x > 0 && map[x][y - 1] ||
            x < r - 1 && map[x][y + 1]
        )
            m_q.push({x, y});
    }
    memorized_q = m_q;
    return false;
}

queue<pair<pair<int, int>, int>> init_queue()
{
    queue<pair<pair<int, int>, int>> result;
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            if (map[j][i] == false)
            {
                if (
                    j > 0 && map[j - 1][i] ||
                    j < c - 1 && map[j + 1][i] ||
                    i > 0 && map[j][i - 1] ||
                    i < r - 1 && map[j][i + 1]
                )
                {
                    result.push({
                        {
                            j, i
                        },
                        0
                    });
                }
            }
        }
    }
    return result;
}

int solve()
{
    int count = 0;
    queue<pair<pair<int, int>, int>> q = init_queue();
    while (!q.empty())
    {
        pair<pair<int, int>, int> top = q.front();
        q.pop();
        int x = top.first.first, y = top.first.second;
        int current_count = top.second;
        // cout << x << ',' << y << ',' << current_count << ',' << count << '\n'; 
        if (current_count != count)
        {
            // cout << "================" << '\n';
            // for (int i=0; i<r; i++)
            // {
            //     for (int j=0; j<c; j++)
            //         cout << (map[j][i] ? 'X' : '.');
            //     cout << '\n';
            // }
            // cout << "================" << '\n';
            if (is_connected())
                return current_count;
            count = current_count;
        }
        if (x > 0 && map[x - 1][y])
        {
            q.push({
                {x - 1, y}, count + 1
            });
            map[x - 1][y] = false;
        }
        if (x < c - 1 && map[x + 1][y])
        {
            q.push({
                {x + 1, y}, count + 1
            });
            map[x + 1][y] = false;
        }
        if (y > 0 && map[x][y - 1])
        {
            q.push({
                {x, y - 1}, count + 1
            });
            map[x][y - 1] = false;
        }
        if (y < r - 1 && map[x][y + 1])
        {
            q.push({
                {x, y + 1}, count + 1
            });
            map[x][y + 1] = false;
        }
    }
}

int main()
{
    cin >> r >> c;
    for (int i=0; i<r; i++)
    {
        char tmp;
        for (int j=0; j<c; j++)
        {
            cin >> tmp;
            if (tmp == 'L')
            {
                if (start_x == -1)
                {
                    start_x = j;
                    start_y = i;
                }
                else
                {
                    end_x = j;
                    end_y = i;
                }
                map[j][i] = false;
            }
            if (tmp == '.')
                map[j][i] = false;
            if (tmp == 'X')
                map[j][i] = true;
        }
    }
    cout << solve();
}