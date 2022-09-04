#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int seq[100000];
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> seq[i];
    sort(seq, seq + n);
    int left_index = 0, right_index = n-1;
    int lowest = INT32_MAX;
    int lowest_left = seq[0], lowest_right = seq[n-1];
    while (left_index < right_index)
    {
        if (seq[left_index] + seq[right_index] == 0)
        {
            cout << seq[left_index] << ' ' << seq[right_index];
            return 0;
        }
        if (abs(seq[left_index] + seq[right_index]) < lowest)
        {
            lowest_left = seq[left_index];
            lowest_right = seq[right_index];
            lowest = abs(lowest_left + lowest_right);
        }
        if (seq[left_index] + seq[right_index] < 0)
            left_index++;
        else
            right_index--;

    }
    cout << lowest_left << ' ' << lowest_right;
}
