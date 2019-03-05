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
int root[2005];
string s[1005];
set<int> arr[2005];

int getRoot(int u) {
    if (root[u] == u) return u;
    return root[u] = getRoot(root[u]);
}

void uni(int u, int v) {
    u = getRoot(u);
    v = getRoot(v);
    if (u != v)
        root[v] = u;
}

vi ss(2005, 1);
vi visited(2005, 0);

void DFS(int u) {
    if (visited[u]) return;
    visited[u] = true;
    for (auto v : arr[u]) {
        DFS(v);
        ss[u] = max(ss[v] + 1, ss[u]);
    }
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n+m; i++) {
        root[i] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '=') {
                uni(i, j+n);
            }
        }
    }

    vi cnt(2005, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '<') {
                int u = getRoot(i);
                int v = getRoot(n+j);
                cnt[u] += arr[v].insert(u).second;
            } else if (s[i][j] == '>') {
                int u = getRoot(i);
                int v = getRoot(n+j);
                cnt[v] += arr[u].insert(v).second;
            }
        }
    }
    
    
    for (int u = 0; u < m+n; u++) {
        DFS(getRoot(u));
    }
    
    

    set<int> res;
    vi rr(2005, 0);
    for (int j = 0; j < n+m; j++) {
        res.insert(ss[getRoot(j)]);
    }
    for (int j = 0; j < n+m; j++) {
        rr[j] = distance(res.begin(), res.find(ss[getRoot(j)])) + 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '<' && rr[i] >= rr[j+n]) {
                cout << "No\n";
                return 0;
            }
            if (s[i][j] == '>' && rr[i] <= rr[j+n]) {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";
    for (int j = 0; j < n; j++) {
        cout << rr[j] << " ";
    }
    cout << "\n";   
    for (int j = n; j < n+m; j++) {
        cout << rr[j] << " ";
    }
    cout << "\n";
    return 0;
}