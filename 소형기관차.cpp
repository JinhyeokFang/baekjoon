#include <iostream>

using namespace std;

int train[50000];
int sum[50000];
int long_train_length;
int short_train_length;
int memory[50000][4];

int get_num_of_passengers_short_train(int start, int end)
{
    return sum[end] - sum[start] + train[start];
}

int solve(int start_index, int num_of_train)
{
    if (start_index >= long_train_length)
        return 0;
    if (num_of_train <= 0)
        return 0;
    int& result = memory[start_index][num_of_train];
    if (result != 0)
        return result;
    if (start_index + short_train_length - 1 < long_train_length)
        result = solve(start_index + short_train_length, num_of_train - 1) + get_num_of_passengers_short_train(start_index, start_index + short_train_length - 1);
    return result = max(result, solve(start_index + 1, num_of_train));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> long_train_length;
    for (int i=0; i<long_train_length; i++) 
    {
        cin >> train[i];
        sum[i] = i == 0 ? train[0] : train[i] + sum[i - 1];
    }
    cin >> short_train_length;
    cout << solve(0, 3);
}