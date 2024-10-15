#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x1, y1, x2, y2, xl, yl, R;
    cin >> x1 >> y1 >> x2 >> y2 >> xl >> yl >> R;

    int dx = max(abs(xl - x1), abs(xl - x2));
    int dy = max(abs(yl - y1), abs(yl - y2));
    int illuminatedNodes = 0;

    for (int x = max(x1, xl - R); x <= min(x2, xl + R); ++x) {
        for (int y = max(y1, yl - R); y <= min(y2, yl + R); ++y) {
            double distance = sqrt((x - xl) * (x - xl) + (y - yl) * (y - yl));
            if (distance <= R) {
                illuminatedNodes++;
            }
        }
    }

    cout << illuminatedNodes << endl;

    return 0;
}