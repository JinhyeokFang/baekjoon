#include <iostream>

using namespace std;

int n;
int numbers[2001];
int memory[2001][2001];
int m;

int answer(int start_index, int end_index)
{
    int& result = memory[start_index][end_index];
    if (result != 0)
        return result;
    if (end_index <= start_index)
        return result = 1;
    if (numbers[start_index] != numbers[end_index])
        return result = 2;
    return result = answer(start_index + 1, end_index - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> numbers[i];
    cin >> m;
    int start, end;
    for (int i=0; i<m; i++)
    {
        cin >> start >> end;
        cout << (bool)(answer(start, end) == 1) << '\n';
    }
}