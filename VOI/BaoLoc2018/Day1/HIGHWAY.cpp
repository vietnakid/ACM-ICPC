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

int n, c1, c2;
vvii arr(100005);


bool isFound = false;
int minCost = INF;
int res = 0;
int minc1 = 0, minc2 = 0;
int k2 = 0, k1 = 0;

void DFS(int u, int father, int cost) {
    // cerr << u << " " << father << endl;
    for(int i = 0; i < arr[u].size(); i++) {
        int v = arr[u][i].first;
        int c = arr[u][i].second;
        
        if (v != father) {
            if (v == c2) {
                isFound = true;
                minCost = min(cost, c);
                arr[u][i].second -= minCost;
                minc2 = arr[u][i].second;
                k2 = u;
                return;
            } else {
                DFS(v, u, min(cost, c));
                if (isFound) {
                    arr[u][i].second -= minCost;
                    if (u == c1) {
                        k1 = v;
                        minc1 = arr[u][i].second;
                    }
                    return;
                }
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
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n >> c1 >> c2;
    for (int i = 0; i < n-1; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        arr[x].push_back({y, c});
        arr[y].push_back({x, c});
    }
    DFS(c1, 0, INF);
    res += minCost;
    // cerr << minc1 << " " << minc2 << endl;
    
    for (int i = 0; i < arr[c1].size(); i++) {
        int v = arr[c1][i].first;
        int c = arr[c1][i].second;
        if (v != c2 && v != k1) {
            minc1 = max(minc1, c);
        }
    }
    for (int i = 0; i < arr[c2].size(); i++) {
        int v = arr[c2][i].first;
        int c = arr[c2][i].second;
        if (v != c1 && v != k2) {
            minc2 = max(minc2, c);
        }
    }
    // cerr << minc1 << " " << minc2 << endl;
    // cout << res << endl;
    
    res += min(minc1, minc2);
    cout << res << endl;
    return 0;
}