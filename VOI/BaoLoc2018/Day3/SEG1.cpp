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
ll it[410005], lazy[410005];

void update(int a, int b, ll x, int node, int left, int right) {
    if (lazy[node] != 0) {
        it[node] = (it[node] + (lazy[node] * (right - left + 1)));
        if (left != right) {
            lazy[node*2] = (lazy[node*2] + lazy[node] + nMod) % nMod;
            lazy[node*2+1] = (lazy[node*2+1] + lazy[node] + nMod) % nMod;
        }
        lazy[node] = 0;
    }
    if (right < a || left > b) return;
    int mid = (left + right) / 2;
    if (a <= left && right <= b) {
        it[node] = (it[node] + (x * (right-left+1)) + nMod) % nMod;
        // cerr << node << " " << left << " " << right << " " << it[node] << " " << lazy[node] << endl;
        if (left != right) {
            lazy[node*2] = (lazy[node*2] + x + nMod) % nMod;
            lazy[node*2+1] = (lazy[node*2+1] + x + nMod) % nMod;
        }
        return;
    }
    update(a, b, x, node*2, left, mid);
    update(a, b, x, node*2+1, mid+1, right);
    it[node] = (it[node*2] + it[node*2+1] + nMod) % nMod;
    lazy[node] = 0;
}

ll get(int a, int b, int node, int left, int right) {
    if (lazy[node] != 0) {
        it[node] = (it[node] + (lazy[node] * (right - left + 1)));
        if (left != right) {
            lazy[node*2] = (lazy[node*2] + lazy[node] + nMod) % nMod;
            lazy[node*2+1] = (lazy[node*2+1] + lazy[node] + nMod) % nMod;
        }
        lazy[node] = 0;
    }

    if (right < a || left > b) return 0;
    if (a <= left && right <= b) {
        // cerr << "GET| " << node << " " << left << " " << right << " " << it[node] << " " << lazy[node] << endl;
        return it[node];
    }
    int mid = (left + right) / 2;
    return get(a, b, node*2, left, mid) + get(a, b, node*2+1, mid+1, right);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	// freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    // freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(i, i, x, 1, 1, n);
    }
    // cerr << it[1] << endl;
    // cerr << endl;
    for (int i = 0; i < m; i++) {
        string t;
        cin >> t;
        if (t == "SET") {
            ll u, v;
            cin >> u >> v;
            ll curVal = get(u, u, 1, 1, n);
            ll x = v - curVal;
            update(u, u, x, 1, 1, n);
        } else if (t == "INC") {
            ll a, b, x;
            cin >> a >> b >> x;
            update(a, b, x, 1, 1, n);
        } else {
            int a, b;
            cin >> a >> b;
            ll res = (get(a, b, 1, 1, n) + nMod) % nMod;
            cout << res << endl;
        }
        // cerr << it[1] << endl;
        // cerr << endl;
    }
    return 0;
}