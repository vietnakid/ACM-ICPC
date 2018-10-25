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

#define INF 1e9+7
#define INFLL 1e18+7
#define esp 1e-9
#define PI 3.14159265

ll nMod = 1e9 + 7;

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};
inline ll LCM(ll a, ll b) {return (a / GCD(a,b)) * b;};

int n, k;
vvi arr;
vi a, b;
vii node;
vi color;
int cnt;

void preOrder(int u) {
    if (u == 0) 
        return;
    a.push_back(u);
    preOrder(node[u].first);
    preOrder(node[u].second);
}

void postOrder(int u) {
    if (u == 0) 
        return;
    postOrder(node[u].first);
    postOrder(node[u].second);
    b.push_back(u);
}

void DFS(int u) {
    color[u] = cnt;
    FOR(i, 0, arr[u].size()) {
        int v = arr[u][i];
        if (color[v] == 0) {
            DFS(v);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int TC; cin >> TC;
    FORE(tc, 1, TC) {
        cout << "Case #" << tc << ":" << endl;
        cin >> n >> k; 
        node = vii(n+1);
        FORE(i, 1, n) {
            int x, y;
            cin >> x >> y;
            node[i] = {x, y};
        }
        a = vi();
        b = vi();
        preOrder(1);
        postOrder(1);
        arr = vvi(n+1);
        color = vi(n+1, 0);
        FOR(i, 0, n) {
            // cerr << a[i] << " " << b[i] << endl;
            arr[a[i]].push_back(b[i]);
            arr[b[i]].push_back(a[i]);
        }
        cnt = 0;
        
        FORE(i, 1, n) {
            if (color[i] == 0) {
                cnt++;
                DFS(i);
            }
        }
        if (cnt < k) {
            cout << "Impossible";
        } else {
            FORE(i, 1, n) {
                if (color[i] > k) {
                    cout << 1 << " ";
                } else {
                    cout << color[i] << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}