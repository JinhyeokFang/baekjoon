#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int k;

void solve(string command, deque<int> dq)
{
    bool reversed = false;
    for (int i=0; i<command.length(); i++)
    {
        if (command[i] == 'R')
        {
            reversed = !reversed;
        }
        else
        {
            if (dq.size() == 0)
            {
                cout << "error" << '\n';
                return; 
            }
            if (reversed)
                dq.pop_back();
            else
                dq.pop_front();            
        }
    }
    if (reversed)
        reverse(dq.begin(), dq.end());
    cout << '[';
    for (int i=0; i<dq.size(); i++)
    {
        cout << dq[i];
        if (i != dq.size() - 1)
            cout << ',';
    }
    cout << ']' << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k;
    for (int i=0; i<k; i++)
    {
        string command;
        int deque_length;
        deque<int> dq;
        cin >> command;
        cin >> deque_length;
        char buffer = ' ';
        int element = 0;
        while (1)
        {
            cin >> buffer;
            if ('0' <= buffer && buffer <= '9')
                element = element * 10 + (buffer - '0');
            else if (element != 0)
            {
                dq.push_back(element);
                element = 0;
            }
            if (buffer == ']')
                break;
        }
        solve(command, dq);
    }
}
