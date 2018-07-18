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

int n, m;
map<string, int> mp;
vvi arr;
int cnt;
vi visit;
vi dfs_num;
vi dfs_low;
vi S;
vector<string> res;

const int UNVISITED = -1;

void tarjanSCC(int u) {
    dfs_num[u] = dfs_low[u] = ++cnt;
    visit[u] = 1;
    S.push_back(u);
    FORE(j, 1, n) {
        if (arr[u][j]) {
            int v = j;
            if (visit[v] == UNVISITED) {
                tarjanSCC(v);
            }
            if (visit[v] == 1) {
                dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            }
        }
    }
    if (dfs_num[u] == dfs_low[u]) {
        while(1) {
            int v = S.back();
            S.pop_back();
            visit[v] = 0;
            if (v == u) {
                cout << res[v] << endl;
                break;
            } else {
                cout << res[v] << ", ";
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
    int testcase = 0;
    while (true) {
        testcase++;
        res.clear();
        mp.clear();
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        cout << "Calling circles for data set "<<testcase<<":" << endl;
        arr = vvi(n+1, vi(n+1, 0));
        cnt = 0;
        res.push_back("testestsetes");
        FOR(i, 0, m) {
            string a, b;
            cin >> a >> b;
            int x, y;
            if (mp[a] == 0) {
                mp[a] = ++cnt;
                res.push_back(a);
            }
            if (mp[b] == 0) {
                mp[b] = ++cnt;
                res.push_back(b);
            }
            x = mp[a];
            y = mp[b];
            // cerr << a << " " << b << " " << x <<  " " << y << endl;
            arr[x][y] = true;
        }
        
        cnt = 0;
        visit = vi(n+1, UNVISITED);
        dfs_num = vi(n+1, 0);
        dfs_low = vi(n+1, 0);
        FORE(i, 1, n) {
            if (visit[i] == UNVISITED) {
                tarjanSCC(i);
            }
        }
    }
    return 0;
}