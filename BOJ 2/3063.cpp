#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef int32_t Int;
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        if (x2 <= x3 || x4 <= x1 || y2 <= y3 || y4 <= y1)
            cout << (x2 - x1)*(y2 - y1) << endl;
        else
        {
            int x, y;

            //x
            if (x1 < x3 && x2 < x4)
                x = x2 - x3;
            else if (x3 < x1 && x4 < x2)
                x = x4 - x1;
            else if (x3 <= x1 && x2 <= x4)
                x = x2 - x1;
            else if (x1 <= x3 && x4 <= x2)
                x = x4 - x3;

            if (y1 < y3 && y2 < y4)
                y = y2 - y3;
            else if (y3 < y1 && y4 < y2)
                y = y4 - y1;
            else if (y3 <= y1 && y2 <= y4)
                y = y2 - y1;
            else if (y1 <= y3 && y4 <= y2)
                y = y4 - y3;

            cout << (x2 - x1)*(y2 - y1) - y*x << endl;
        }
    }
}