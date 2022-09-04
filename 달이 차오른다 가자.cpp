#include <iostream>
#include <queue>

using namespace std;

char map[50][50];
char visited[50][50][(1 << 6)];
int n, m;

bool possible(char x, char y, char key)
{
    if (x < 0 || x >= m || y < 0 || y >= n)
        return false;
    if (map[x][y] == '#')
        return false;
    if (visited[x][y][key])
        return false;
    if (
        map[x][y] == '.' || map[x][y] == '1' ||
        map[x][y] == 'a' || map[x][y] == 'b' || 
        map[x][y] == 'c' || map[x][y] == 'd' || 
        map[x][y] == 'e' || map[x][y] == 'f'
    )
        return true;
    if (map[x][y] == 'F' && key & (1 << 5))
        return true;
    if (map[x][y] == 'E' && key & (1 << 4))
        return true;
    if (map[x][y] == 'D' && key & (1 << 3))
        return true;
    if (map[x][y] == 'C' && key & (1 << 2))
        return true;
    if (map[x][y] == 'B' && key & (1 << 1))
        return true;
    if (map[x][y] == 'A' && key & (1 << 0))
        return true;
    return false;
}

char update_key(char x, char y, char key)
{
    if (map[x][y] == 'f')
        key = key | (1 << 5);
    if (map[x][y] == 'e')
        key = key | (1 << 4);
    if (map[x][y] == 'd')
        key = key | (1 << 3);
    if (map[x][y] == 'c')
        key = key | (1 << 2);
    if (map[x][y] == 'b')
        key = key | (1 << 1);
    if (map[x][y] == 'a')
        key = key | (1 << 0);
    return key;
}

void solve(char x, char y)
{
    int result = 100000;
    queue<pair<pair<char, char>, pair<char, int>>> q; // x,y key,count
    q.push({{x, y}, {0,0}});
    map[x][y] = '.';
    visited[x][y][0] = true;
    while (!q.empty())
    {
        pair<pair<char, char>, pair<char, int>> item = q.front();
        char x = item.first.first;
        char y = item.first.second;
        char key = item.second.first;
        int count = item.second.second;
        
        q.pop();
        if (map[x][y] == '1')
        {
            cout << count;
            return;
        }
        key = update_key(x, y, key);
        if (possible(x - 1, y, key))
        {
            visited[x - 1][y][key] = true;
            visited[x - 1][y][0] = true;
            q.push({{x - 1, y}, {key, count + 1}});
        }
        if (possible(x + 1, y, key))
        {
            visited[x + 1][y][key] = true;
            visited[x + 1][y][0] = true;
            q.push({{x + 1, y}, {key, count + 1}});
        }
        if (possible(x, y - 1, key))
        {
            visited[x][y - 1][key] = true;
            visited[x][y - 1][0] = true;
            q.push({{x, y - 1}, {key, count + 1}});
        }
        if (possible(x, y + 1, key))
        {
            visited[x][y + 1][key] = true;
            visited[x][y + 1][0] = true;
            q.push({{x, y + 1}, {key, count + 1}});
        }
    }
    cout << -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    char x, y;
    for (char i=0; i<n; i++)
    {
        for (char j=0; j<m; j++)
        {
            cin >> map[j][i];
            if (map[j][i] == '0')
            {
                x = j;
                y = i;
            }
        }
    }
    solve(x, y);
}