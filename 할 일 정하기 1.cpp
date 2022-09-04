include <iostream>

using namespace std;

int n;
int work_time[21][21];
int memory[(1 << 20)][21];

int solve(int work_list, int current_index)
{
    int& result = memory[work_list][current_index];
    if (result != 0)
        return result;
    result = INT32_MAX / 2;
    if (current_index == n)
        return result = (work_list == ((1 << n) - 1) ? 0 : result);
    for (int i=0; i<n; i++)
    {
        if ((work_list & (1 << i)) == 0)
            result = min(result, solve(work_list | (1 << i), current_index + 1) 
                + work_time[current_index][i]);
    }
    return result;
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
            cin >> work_time[i][j];
        }
    }
    cout << solve(0,0);
}
