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

int n, m;
vii edge;
vvi arr;
vi dir;
bool isOk = true;

void DFS(int u) {
    for (auto v : arr[u]) {
        if (!isOk) return;
        if (dir[v] == 0) {
            dir[v] = -dir[u];
            DFS(v);
        } else {
            if (dir[v] == dir[u]) {
                isOk = false;
                return;
            }
        }
    }
}

void printResult() {
    cout << "YES\n";
    for (int i = 0; i < m; i++) {
        if (dir[edge[i].first] == 1) {
            cout << 0;
        } else {
            cout << 1;
        }
    }
    cout << "\n";
    exit(0);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
 	cin >> n >> m;
    arr.resize(n);
    edge.resize(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edge[i].first = u;
        edge[i].second = v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    dir.resize(n, 0);
    dir[0] = 1;
    isOk = true;
    DFS(0);
    if (isOk) {
        printResult();
    }
    dir.resize(n, 0);
    dir[0] = -1;
    isOk = true;
    DFS(0);
    if (isOk) {
        printResult();
    }
    cout << "NO\n";
    return 0;
}