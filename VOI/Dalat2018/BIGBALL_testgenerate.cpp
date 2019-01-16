#include <bits/stdc++.h>

using namespace std;

const int maxX = 1000000000;
int n = 100000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
    freopen("BIGBALL.inp", "w", stdout);
    srand(time(NULL));
    int xa, ya, za, xb, yb, zb;
    xa = rand() % maxX;
    ya = rand() % maxX;
    za = rand() % maxX;
    xb = rand() % maxX;
    yb = rand() % maxX;
    zb = rand() % maxX;
    printf("%d\n", n);
    printf("%d %d %d\n", xa, ya, za);
    printf("%d %d %d\n", xb, yb, zb);
    for (int i = 0; i < n; i++) {
        int x, y, z;
        x = rand() % maxX;
        y = rand() % maxX;
        z = rand() % maxX;
        printf("%d %d %d\n", x, y, z);
    }
    return 0;
}