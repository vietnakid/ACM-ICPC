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

const int N = 31;
int n, m;
int t=0;
vi Visited, Assigned;
vvi a;

bool visit(int u) {
    if (Visited[u]!=t) 
        Visited[u]=t; 
    else 
        return false;
    // cerr << " u = " << u << " " << Visited[u] << " " << t << endl;
    for (int i=0; i < a[u].size(); i++) {
        int v = a[u][i];
        // cerr << v << " " << a[u].size() << endl;
        if (!Assigned[v] || visit(Assigned[v])) { 
            Assigned[v]=u; 
            return true; 
        }
    }
    return false;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    cin >> n;
    vvi arr(n, vi(n));
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cin >> arr[i][j];
        }
    }

    int l = 1, r = 1000000;
    int res = 0;
    while (l <= r) {
    // FOR(i, 0, 1) {
        int mid = (l+r) / 2;
        // mid = 2;
        // cerr << mid << endl;
        a = vvi(n+1);
        Visited = vi(n+1, 0);
        Assigned = vi(n+1, 0);
        FOR(i, 0, n) {
            FOR(j, 0, n) {
                if (arr[i][j] >= mid) {
                    a[i].push_back(j+1);
                }
            }
        }

        t = 0;
        int Count = 0;
        
        for (int i=0; i<n; i++) {
            t++;
            Count += visit(i);
        }
        // cerr << mid << " " << l << " " << r << " " << Count << endl;
        if (Count == n) {
            res = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    cout << res << endl;
    return 0;
}