#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

map<string, int> mp;
string a, b;
vvi arr;
int n;
vector<string> names;

bool canTransform(string a, string b) {
    if (a.size() != b.size()) {
        return false;
    }
    int cnt = 0;
    FOR(i, 0, a.size()) {
        if (a[i] != b[i]) {
            cnt++;
        }
    }
    return cnt <= 1;
}

void init() {
    n = mp.size();
    names = vector<string>(n);
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        names[it->second] = it->first; 
    }
    arr = vvi(n);
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            if (i != j) {
                if (canTransform(names[i], names[j])) {
                    arr[i].push_back(j);
                    // cout << names[i] << " - " << names[j] << " " << i << " " << j << endl;
                }
            }
        }
    }
}

void sovle() {
    int src = mp[a];
    int dst = mp[b];
    // cout << a << " " <<  b << " " << src << " " << dst << endl;
    vi d(n, INF);
    d[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == dst) {
            cout << a << " " << b << " " << d[u] << endl;
            break;
        }
        FOR(i, 0, arr[u].size()) {
            int v = arr[u][i];
            if (d[v] == INF) {
                d[v] = d[u] + 1;
                q.push(v);
                // cout << v << " " << d[v] << " " << names[v] << endl;
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
    string s;
    getline(cin, s);
    stringstream ss(s);
    int TC;
    ss >> TC;
    getline(cin, s);
    while (TC--) {
        mp.clear();
        names.clear();
        int cnt = 0;
        while (true) {
            getline(cin, s);
            if (s == "*") {
                init();
                while (true) {
                    getline(cin, s);
                    stringstream ss(s);
                    a = "";
                    ss >> a >> b;
                    // cout << a << " " << a.size() << endl;
                    if (a.size() == 0) {
                        break;
                    }
                    sovle();
                }
                break;
            } else {
                mp[s] = cnt;
                // cerr << s << " " << mp[s] << endl;
                cnt++;
            }
        }
        if (TC != 0)
            cout << endl;
    }
    return 0;
}