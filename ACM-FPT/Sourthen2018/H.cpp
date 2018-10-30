#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector< vii> vvii;

#define FOR(i, a, b) \
    for (int i = (a); i < (b); i++)
#define FORE(i, a, b) \
    for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) \
    for (int i = (a); i >= (b); i--)

#define INF 1000000007
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n, m;
int d[1005][1005];
bool isFree1[1005][1005], isFree2[1005][1005], isFree3[1005][1005];
ii start, fin;
queue<ii> qu;

void input() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    ss >> n >> m;
    memset(isFree1, true, sizeof(isFree1));
    memset(isFree2, true, sizeof(isFree2));
    memset(isFree3, true, sizeof(isFree3));
    FOR(i, 0, n) {
        getline(cin, s);
        FOR(j, 0, m) {
            if (s[j] == 'S') {
                start = make_pair(i, j);
            } else if (s[j] == 'F') {
                fin = make_pair(i, j);
            } else if (s[j] == '#') {
                isFree1[i][j] = false;
                isFree3[i][j] = false;
            }
        }
    }
    FOR(i, 0, n) {
        getline(cin, s);
        FOR(j, 0, m) {
            if (s[j] == 'S') {
                start = make_pair(i, j);
            } else if (s[j] == 'F') {
                fin = make_pair(i, j);
            } else if (s[j] == '#') {
                isFree2[i][j] = false;
                isFree3[i][j] = false;
            }
        }
    }
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve(bool isFree[][1005]) {
    while (!qu.empty()) {
        ii p = qu.front();
        qu.pop();
        // cerr << p.first << " " << p.second << endl;
        FOR(i, 0, 4) {
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && isFree[x][y]) {
                // cerr << "X, Y = " <<  x << " " << y << endl;
                d[x][y] = d[p.first][p.second] + 1;
                isFree[x][y] = false;
                qu.push(make_pair(x, y));
            }
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);

    input();
    int res1 = -1, res2 = -1, res3 = -1;

    d[start.first][start.second] = 0;
    isFree3[start.first][start.second] = false;
    qu.push(start);
    solve(isFree3);
    if (isFree3[fin.first][fin.second]) {
        res3 = -1;
    } else {
        res3 = d[fin.first][fin.second] - 1;
    }

    d[start.first][start.second] = 0;
    isFree1[start.first][start.second] = false;
    qu.push(start);
    solve(isFree1);
    if (isFree1[fin.first][fin.second]) {
        res1 = -1;
    } else {
        res1 = d[fin.first][fin.second] - 1;
    }

    d[start.first][start.second] = 0;
    isFree2[start.first][start.second] = false;
    qu.push(start);
    solve(isFree2);
    if (isFree2[fin.first][fin.second]) {
        res2 = -1;
    } else {
        res2 = d[fin.first][fin.second] - 1;
    }

    if (res1 == res2 && res2 == res3) {
        cout << res1 << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}