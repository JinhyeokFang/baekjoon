#include <iostream>

using namespace std;

class vector2
{
public:
    int x, y;

    vector2 (int x, int y) : x(x), y(y) {}
    vector2 operator -(vector2& second)
    {
        return vector2(x - second.x, y - second.y);
    }
    static int cross(vector2& first, vector2& second)
    {
        return first.x * second.y - second.x * first.y;
    }
};

int ccw(vector2 p1, vector2 p2, vector2 p3)
{
    vector2 a = p2 - p1, b = p3 - p1;
    int result = vector2::cross(a, b);
    return (result < 0) ? 1 : (result == 0) ? 0 : -1;
}

int main()
{
    int p1x, p2x, p3x, p1y, p2y, p3y;
    cin >> p1x >> p1y;
    cin >> p2x >> p2y;
    cin >> p3x >> p3y;
    int result = ccw(vector2(p2x, p2y), vector2(p1x, p1y), vector2(p3x, p3y));
    cout << result;
}
