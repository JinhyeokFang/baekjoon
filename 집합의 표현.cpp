#include <iostream>

using namespace std;

int n, m;
int parent_nodes[1000000];

int find_root_node(int current)
{
    if (parent_nodes[current] == current)
        return current;
    return parent_nodes[current] = find_root_node(parent_nodes[current]);
}

bool answer(int a, int b)
{
    return find_root_node(a) == find_root_node(b);
}

void change_parent_node(int a, int b)
{
    parent_nodes[find_root_node(a)] = find_root_node(b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i=0; i<1000000; i++)
        parent_nodes[i] = i;
    for (int i=0; i<m; i++)
    {
        int command, a, b;
        cin >> command >> a >> b;
        if (command)
            cout << (answer(a, b) ? "YES" : "NO") << '\n';
        else
            change_parent_node(a, b);        
    }
}
