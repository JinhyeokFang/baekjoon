#include <iostream>
#include <stack>

using namespace std;

int h, w;
bool map[500][500]; //h, w

int get_point_from_left(int height)
{
    for (int index = 0; index < w; index++)
    {
        if (map[height][index])
            return index;
    }
    return -1;
}

int get_point_from_right(int height)
{
    for (int index = w - 1; index >= 0; index--)
    {
        if (map[height][index])
            return index;
    }
    return -1;
}

int get_score_of_line(int height)
{
    int left_index = get_point_from_left(height), right_index = get_point_from_right(height);
    if (left_index == right_index)
        return 0;
    int sum = 0;
    for (int index = left_index; index < right_index; index++)
        sum += !map[height][index];
    return sum; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> h >> w;
    for (int i=0; i<w; i++)
    {
        int temp;
        cin >> temp;
        for (int j=0; j<temp; j++)
        {
            map[j][i] = true;
        }
    }
    int sum = 0;
    for (int i=0; i<h; i++)
        sum += get_score_of_line(i);
    cout << sum;
}