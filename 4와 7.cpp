#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    n += 1;
    string result = "";
    for (int i=n; i>0; i/=2)
    {
        result = ((i % 2) ? '7' : '4') + result;
    }
    cout << result.substr(1, result.size() - 1);
}
