using namespace std;

#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>

#define Vector vector<short>
#define Map map<Vector, ulong>
#define ulong unsigned long

void solve();
void solve(ulong*);
void setLength(int, int, int);
int nextLine();

int  n;   /* number of lines */
int  m;   /* number of columns */
Vector c; /* number of columns (length) of each line */
Map memo; /* memoization */

int main() {
    cin >> n >> m;

    {
        short length;

        for (int x = 0; (x < n); x++) {
            cin >> length;
            c.push_back(length);
        }
    }

    solve();
    return 0;
}

void solve() {
    ulong result;

    if ((n < 1) || (c[n-1] < 1)) {
        result = 0;
    } else if ((n == 1) || (c[n-2] < 2)) {
        result = 1;
    } else {
        result = 0;
        solve(&result);
    }

    cout << result << endl;
}

void solve(ulong* result) {
    {
        Map::iterator it = memo.find(c);

        if (it != memo.end()) {
            *result += it->second;
            return;
        }
    }

    int x = nextLine(); /* find next line able to receive a square */
    int y = c[x]-1;

    if (y < 0) {
        *result += 1;
        return;
    }

    ulong subresult = 0; /* subresult (for memoization purposes) */
    int size = 1; /* size of the square */

    do {
        setLength(x, x+size, y-size+1); /* "remove" the square */
        solve(&subresult); /* solve the new configuration */

        size++;
    } while ((y-size+1 >= 0) && (x+size-1 < n) && (c[x+size-1] == y+1));

    setLength(x, x+(--size), y+1);

    /* memoize and add to the final result */
    *result += (memo[c] = subresult);
}

void setLength(int fromX, int toX, int length) {
    while (fromX < toX) {
        c[fromX++] = length;
    }
}

int nextLine() {
    int x = n-1;
    while ((x > 0) && (c[x-1] >= c[x])) x--;
    return x;
}