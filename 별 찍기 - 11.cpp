#include <iostream>
#include <cmath>

using namespace std;

int n;
bool star[8000][8000];

void print_map();
void put_basic_triangle(int x, int y); // 왼쪽 위 코너
void put_triangle(int level, int x, int y);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    put_triangle(n/3, 0, 0);
    print_map();
}

void put_basic_triangle(int x, int y)
{
    star[x+2][y] = true;

    star[x+1][y+1] = true;
    star[x+3][y+1] = true;

    star[x][y+2] = true;
    star[x+1][y+2] = true;
    star[x+2][y+2] = true;
    star[x+3][y+2] = true;
    star[x+4][y+2] = true;
}

void put_triangle(int level, int x, int y)
{
    if (level == 1)
    {
        put_basic_triangle(x,y);
        return;
    }
    put_triangle(level/2, x+level*3/2, y);
    put_triangle(level/2, x, y+level*3/2);
    put_triangle(level/2, x+level*3, y+level*3/2);
}

void print_map()
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n*2-1; j++)
        {
            if (star[j][i])
                cout << '*';
            else
                cout << ' ';
        }
        cout << '\n';
    }
}