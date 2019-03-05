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

int n;
vi arr[300005];
int num[300005];
int f[300005][3];
int res = 0;
int total[3];

void DFS(int u, int father) {
    for (int v : arr[u]) {
        if (v != father) {
            DFS(v, u);
            for (int i = 1; i < 3; i++) {
                f[u][i] += f[v][i];
                if (f[v][i] == total[i] && f[v][3-i] == 0) {
                    res++;
                }
            }
        }
    }
    f[u][num[u]]++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        total[num[i]]++;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (arr[i].size() == 1) {
            DFS(i, 0);
            break;
        }
    }
    cout << res << "\n";
    return 0;
}