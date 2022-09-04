#include <iostream>

using namespace std;

string back[3], top[3], front[3], bottom[3], leftside[3], rightside[3];

void turn_part(char& c1, char& c2, char& c3, char& c4, bool clockwise)
{
    char tmp = c1;
    if (clockwise)
    {
        c1 = c2;c2 = c3;c3 = c4;c4 = tmp;
    } else {
        c1 = c4;c4 = c3;c3 = c2;c2 = tmp;
    }
}

void turn_side_part(char& c1, char& c2, char& c3, char& c4, char& c5, char& c6, char& c7, char& c8, char& c9, char& c10, char& c11, char& c12, bool clockwise)
{
    turn_part(c1, c4, c7, c10, clockwise);
    turn_part(c2, c5, c8, c11, clockwise);
    turn_part(c3, c6, c9, c12, clockwise);
}

void turn(char side, bool clockwise)
{
    string* s = back;
    if (side == 'B')
    {
        s = back;
        turn_side_part(
            leftside[0][0], leftside[1][0], leftside[2][0],
            top[0][0], top[1][0], top[2][0],
            rightside[0][0], rightside[1][0], rightside[2][0],
            bottom[2][2], bottom[1][2], bottom[0][2],
            clockwise
        );
    }
    if (side == 'U')
    {
        s = top;
        turn_side_part(
            leftside[2][0], leftside[2][1], leftside[2][2],
            front[0][0], front[1][0], front[2][0],
            rightside[0][2], rightside[0][1], rightside[0][0],
            back[2][2], back[1][2], back[0][2],
            clockwise
        );
    }
    if (side == 'F')
    {
        s = front;
        turn_side_part(
            leftside[2][2], leftside[1][2], leftside[0][2],
            bottom[0][0], bottom[1][0], bottom[2][0],
            rightside[2][2], rightside[1][2], rightside[0][2],
            top[2][2], top[1][2], top[0][2],
            clockwise
        );
    }
    if (side == 'D')
    {
        s = bottom;
        turn_side_part(
            leftside[0][2], leftside[0][1], leftside[0][0],
            back[0][0], back[1][0], back[2][0],
            rightside[2][0], rightside[2][1], rightside[2][2],
            front[2][2], front[1][2], front[0][2],
            clockwise
        );
    }
    if (side == 'L')
    {
        s = leftside;
        turn_side_part(
            top[0][2], top[0][1], top[0][0],
            back[0][2], back[0][1], back[0][0],
            bottom[0][2], bottom[0][1], bottom[0][0],
            front[0][2], front[0][1], front[0][0],
            clockwise
        );
    }
    if (side == 'R')
    {
        s = rightside;
        turn_side_part(
            top[2][2], top[2][1], top[2][0],
            back[2][2], back[2][1], back[2][0],
            bottom[2][2], bottom[2][1], bottom[2][0],
            front[2][2], front[2][1], front[2][0],
            !clockwise
        );
    }
    turn_part(s[0][0], s[0][2], s[2][2], s[2][0], clockwise);
    turn_part(s[1][0], s[0][1], s[1][2], s[2][1], clockwise);
}

int c, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> c;
    for (int i=0; i<c; i++)
    {
        cin >> n;
        for (int k=0; k<3; k++)
        {
            back[k] = "ooo";
            top[k] = "www";
            front[k] = "rrr";
            bottom[k] = "yyy";
            leftside[k] = "ggg";
            rightside[k] = "bbb";
        }
        for (int j=0; j<n; j++)
        {
            string command, side;
            bool clockwise;
            cin >> command;
            turn(command[0], command[1] == '+');
        }
        for (int y=0; y<3; y++)
        {
            for (int x=0; x<3; x++)
                cout << top[x][y];
            cout << '\n';
        }
    }
    
}
