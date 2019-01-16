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

#define INF 1000000007
#define INFLL 1000000000000000000
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

vector<ii> arr(3);
bool isMark[1005][1005], isFree[1005][1005];
ii trace[1005][1005];
queue<ii> q;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

ii meetPoint = {-1, -1};

set<ii> res;

void resetQ() {
    while (!q.empty()) q.pop();
}

void BFS() {
    while (!q.empty()) {
        ii u = q.front();
        if (isMark[u.first][u.second]) {
            meetPoint = {u.first, u.second};
            return;
        }
        // cerr << u.first << " " << u.second << endl;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = u.first + dx[i];
            int y = u.second + dy[i];
            if (x < 0 || x > 1000 || y < 0 || y > 1000) continue;
            if (!isFree[x][y]) {
                isFree[x][y] = true;
                q.push({x, y});
                trace[x][y] = u;
                if (isMark[x][y]) {
                    meetPoint = {x, y};
                    return;
                }
            }
        }
    }
}

void traceBack(int x, int y) {
    while (x != -1) {
        res.insert({x, y});
        ii tmp = trace[x][y];
        x = tmp.first;
        y = tmp.second;
        // cerr << x << " " << y << endl;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    for (int i = 0; i < 3; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    memset(isMark, 0, sizeof(isMark));
    memset(isFree, 0, sizeof(isFree));
    q.push(arr[2]);
    isFree[arr[2].first][arr[2].second] = true;
    for (int x = min(arr[0].first, arr[1].first); x <= max(arr[0].first, arr[1].first); x++) {
        for (int y = min(arr[0].second, arr[1].second); y <= max(arr[0].second, arr[1].second); y++) {
            isMark[x][y] = 1;
        }
    }
    for (int x = 0; x < 1005; x++) {
        for (int y = 0; y < 1005; y++) {
            trace[x][y] = {-1, -1};
        }
    }
    BFS();
    traceBack(meetPoint.first, meetPoint.second);
    ii _meetPoint = meetPoint;

    // cerr << meetPoint.first << " " << meetPoint.second << endl;
    // first meet point

    resetQ();
    memset(isMark, 0, sizeof(isMark));
    memset(isFree, 0, sizeof(isFree));
    q.push(_meetPoint);
    isFree[_meetPoint.first][_meetPoint.second] = true;
    isMark[arr[0].first][arr[0].second] = 1;
    for (int x = 0; x < 1005; x++) {
        for (int y = 0; y < 1005; y++) {
            trace[x][y] = {-1, -1};
        }
    }
    BFS();
    traceBack(meetPoint.first, meetPoint.second);
    // cerr << meetPoint.first << " " << meetPoint.second << endl;

    resetQ();
    memset(isMark, 0, sizeof(isMark));
    memset(isFree, 0, sizeof(isFree));
    q.push(_meetPoint);
    isFree[_meetPoint.first][_meetPoint.second] = true;
    isMark[arr[1].first][arr[1].second] = 1;
    for (int x = 0; x < 1005; x++) {
        for (int y = 0; y < 1005; y++) {
            trace[x][y] = {-1, -1};
        }
    }
    BFS();
    traceBack(meetPoint.first, meetPoint.second);
    // cerr << meetPoint.first << " " << meetPoint.second << endl;

    cout << res.size() << endl;
    for (auto x : res) {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}