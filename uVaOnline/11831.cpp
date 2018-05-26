#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

#define INF 2e9 // 2e9
#define INFLL 2e18 // 2e18
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

priority_queue< ll, vector<ll>, greater<ll> > heap;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    while (true) {
        int n = 0, m = 0, k = 0;
        cin >> n >> m >> k;
        if (n ==0 && m == 0 && k == 0) {
            break;
        }
        vector<string> arr(n);
        int x, y, dir;
        FOR(i, 0, n) {
            cin >> arr[i];
            FOR(j, 0, m) {
                if (arr[i][j] != '*' && arr[i][j] != '.' && arr[i][j] != '#') {
                    x = i; y = j;
                    switch (arr[i][j]) {
                        case 'N': dir = 0; break;
                        case 'O': dir = 1; break;
                        case 'S': dir = 2; break;
                        case 'L': dir = 3; break;
                    }
                }
            }
        }
        // O = North, 1 = West, 2 = South, 3 = East
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        string s;
        cin >> s;
        int cnt = 0;
        FOR(i, 0, s.size()) {
            // cout << x << " " << y << " " << dir << endl;
            char c = s[i];
            switch (c) {
                case 'F': {
                    int xx = x + dx[dir];
                    int yy = y + dy[dir];
                    if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
                        if (arr[xx][yy] != '#') {
                            x = xx;
                            y = yy;
                            if (arr[x][y] == '*') {
                                arr[x][y] = '.';
                                cnt++;
                            }
                        }
                    }
                    break;
                }
                case 'D': dir = ((dir-1) + 4) % 4; break;
                case 'E': dir = (dir + 1) % 4; break;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}