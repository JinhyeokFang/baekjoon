#include <iostream>
#include <vector>

using namespace std;

int n;
int initial_map[400];

vector<int> merged_lines(vector<int> lines)
{ // 4 4 2 -> // 8 2
    vector<int> result;
    // for (int i=0; i<lines.size(); i++)
    //     cout << ',' << lines[i];
    while (!lines.empty())
    {
        if (lines.size() > 1 && lines[0] == lines[1])
        {
            result.push_back(lines[0] * 2);
            lines.erase(lines.begin());
            lines.erase(lines.begin());
        }
        else
        {
            result.push_back(lines[0]);
            lines.erase(lines.begin());
        }
    }
    // for (int i=0; i<result.size(); i++)
    //     cout << '|' << result[i];
    // cout << '\n';
    return result;
}

int solve(int count, int map[400]);

int move_and_call_solve(int direction, int count, int map[400])
{
    if (direction == 1)
    {
        for (int i=0; i<n; i++)
        { // 4 0 2 2 -> // 4 2 2 -> // 4 4
            vector<int> lines;
            for (int j=0; j<n; j++)
                if (map[j+i*20])
                    lines.push_back(map[j+i*20]);
            lines = merged_lines(lines);
            for (int j=0; j<n; j++)
            {
                if (j < lines.size())
                    map[j+i*20] = lines[j];
                else
                    map[j+i*20] = 0;                
            }
        }
    }
    if (direction == 2)
    {
        for (int i=0; i<n; i++)
        { // 4 0 2 2 -> // 4 2 2 -> // 4 4
            vector<int> lines;
            for (int j=n-1; j>=0; j--)
                if (map[j+i*20])
                    lines.push_back(map[j+i*20]);
            lines = merged_lines(lines);
            for (int j=n-1; j>=0; j--)
            {
                if (n-1-j < lines.size())
                    map[j+i*20] = lines[n-1-j];
                else
                    map[j+i*20] = 0;                
            }
        }
    }
    if (direction == 3)
    {
        for (int j=0; j<n; j++)
        { // 4 0 2 2 -> // 4 2 2 -> // 4 4
            vector<int> lines;
            for (int i=0; i<n; i++)
                if (map[j+i*20])
                    lines.push_back(map[j+i*20]);
            lines = merged_lines(lines);
            for (int i=0; i<n; i++)
            {
                if (i < lines.size())
                    map[j+i*20] = lines[i];
                else
                    map[j+i*20] = 0;                
            }
        }
    }
    if (direction == 4)
    {
        for (int j=0; j<n; j++)
        { // 4 0 2 2 -> // 4 2 2 -> // 4 4
            vector<int> lines;
            for (int i=n-1; i>=0; i--)
                if (map[j+i*20])
                    lines.push_back(map[j+i*20]);
            lines = merged_lines(lines);
            for (int i=n-1; i>=0; i--)
            {
                if (n-1-i < lines.size())
                    map[j+i*20] = lines[n-1-i];
                else
                    map[j+i*20] = 0;                
            }
        }
    }
    return solve(count + 1, map);
}

int get_result(int map[400])
{
    int result = 0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            result = max(result, map[j+i*20]);
        }
    }
    return result;
}

int solve(int count, int map[400])
{
    if (count == 5)
        return get_result(map);
    int result = 0;
    int map1[400], map2[400], map3[400], map4[400];
    for (int i=0; i<400; i++)
        map1[i] = map2[i] = map3[i] = map4[i] = map[i];
    result = max(result, move_and_call_solve(1, count, map1));
    result = max(result, move_and_call_solve(2, count, map2));
    result = max(result, move_and_call_solve(3, count, map3));
    result = max(result, move_and_call_solve(4, count, map4));
    return result;
}

int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cin >> initial_map[j+i*20];
        }
    }
    cout << solve(0, initial_map);
}