#include <iostream>
#include <vector>

using namespace std;

int n, k;
int weight[101];
int value[101];
int memory[101][100001];

int biggest_value(int current_item, int max_weight)
{
    int& result = memory[current_item][max_weight];
    if (result != 0)
        return result;
    if (current_item == n - 1)
    {
        if (max_weight - weight[current_item] >= 0)
            return result = value[current_item];
        return result = 0;
    }
    if (max_weight - weight[current_item] >= 0)
        return result = max(
            biggest_value(current_item + 1, max_weight - weight[current_item]) + value[current_item],
            biggest_value(current_item + 1, max_weight)
        );
    return result = biggest_value(current_item + 1, max_weight);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i=0; i<n; i++)
    {
        cin >> weight[i] >> value[i];
    }
    cout << biggest_value(0, k);
}
